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
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> f(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, n){
    cin >> f[i];
  }
  sort(a.begin(), a.end());
  //sort(f.begin(), f.end(), greater<int>());
  sort(f.rbegin(), f.rend());
  vector<ll> af(n);
  rep(i, n){
    af[i]=(ll)a[i]*f[i];
  }
  ll l=-1, r=1e12;
  while(l+1<r){
    ll m=(l+r)/2;
    ll num=0;
    rep(i, n){
      if(af[i]>m){
        ll tmp=(af[i]-m-1)/f[i]+1;
        num+=tmp;
      }
    }
    if(num<=k){
      r=m;
    } else {
      l=m;
    }
  }
  cout << r << endl;
  return 0;
}
