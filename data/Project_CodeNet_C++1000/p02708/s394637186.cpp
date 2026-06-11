#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n , k;
  cin >> n >> k;
  vector<ll> a(n+1);
  repo(i, n){
    a[i]=a[i-1]+i;
  }
  ll ans=0;
  for(int i=k; i<=n; i++){
    ans+=a[n]-a[n-i]-a[i-1]+1;
    ans%=mod;
  }
  ans++;
  ans%=mod;
  cout << ans << endl;
  return 0;
}
