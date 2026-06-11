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

lli mul(lli a,lli b){
  return (a%mod * b%mod)%mod;
}

lli add(lli a,lli b){
  return (a%mod + b%mod)%mod;
}

lli sub(lli a,lli b){
  return (a%mod-b%mod+mod)%mod;
}
 
//############################ENDOFTEMPLATE############################



void solve(){
  int n;
  cin>>n;
  vector<vector<pii>> test(n);

  for(int i = 0;i<n;i++){
    int a;
    cin>>a;
    for(int j = 0;j<a;j++){
      int x,y;
      cin>>x>>y;
      test[i].push_back({x,y});

    }
  }

  int max_mask = 1<<n;

  int ans = 0;
  for(int mask = 0;mask<max_mask;mask++){
    bool flag = true;
    for(int i = 0;i<n;i++){
      //cout<<(mask&(1<<i));
      if((mask & (1<<i))==0) continue;

      for(auto c:test[i]){
        int x = c.first; int y = c.second;
        x--;
        if((y==0 &&(mask&(1<<x))!=0) || (y==1 && (mask&(1<<x))==0))
          flag = false;
      }
    }
    //cout<<" ";

    //cout<<mask<<" "<<flag<<endl;

    if(flag){
      ans = max(ans,__builtin_popcount(mask));
    }
  }

  cout<<ans;
}

 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}