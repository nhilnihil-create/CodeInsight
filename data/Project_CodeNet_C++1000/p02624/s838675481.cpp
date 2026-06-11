#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
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




void solve(){
  lli n;
  cin>>n;

  lli ans = 0;
  for(int i = 1;i<=n;i++){
    lli m = n/i;
    ans = ans+ (m*(m+1)*i)/2;
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