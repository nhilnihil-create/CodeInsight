#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
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

bool compare(vi& a,vi& b){
  if(a[1]<b[1]){
    return true;
  }
  else if(a[1]==b[1]){
    if(a[0]<b[0])
      return true;
  }

  return false;
}


void solve(){
  int n;
  cin>>n;

  vector<vi> inv(n,vi(2));

  for(int i = 0;i<n;i++){
    int x,l;
    cin>>x>>l;
    inv[i][0] = x-l;
    inv[i][1] = x+l;
  }

  sort(inv.begin(),inv.end(),compare);

  int ans = 1;
  int cl = inv[0][0],cr = inv[0][1];
  //cout<<cl<<" "<<cr<<endl;
  for(int i = 1;i<n;i++){
    int x = inv[i][0] ,y = inv[i][1];
    //cout<<x<<" "<<y<<endl;
    if(x>=cr){
      cl = x;
      cr = y;
      //cout<<cl<<" "<<cr<<endl;
      ans++; 
    }
  }

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