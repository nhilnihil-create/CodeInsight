#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
//############################ENDOFTEMPLATE############################
vector<vector<int>> v;
int ans = 0;
int n,m;

void dfs(int i,int j,vi& curr){
  if(j>m)
    return;
  if(i>n)
    return;


  if(i==n){
    //for(auto s:curr)
      //cout<<s<<" ";

    int score = 0;
    for(auto s:v){
      int a = s[0] , b = s[1], c = s[2], d = s[3];
      if(curr[b-1]-curr[a-1]==c)
        score+=d;

    }
    //cout<<score<<endl;
    ans = max(ans,score);
    
    return;
  }

  curr.push_back(j);
  dfs(i+1,j,curr);
  //dfs(i+1,j+1,curr);
  curr.pop_back();
  dfs(i,j+1,curr);


  return;

}

void solve(){
  int q;
  cin>>n>>m>>q;

  v.resize(q,vector<int>(4));

  for(int i = 0;i<q;i++){
    cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
  }

  vi curr;
  //for(int i = 1;i<=m;i++)
    dfs(0,1,curr);

  cout<<ans;

}

 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("moobuzz.in","r",stdin);
  //freopen("moobuzz.out","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}