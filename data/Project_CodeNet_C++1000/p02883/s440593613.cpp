#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(a);
  sort(f);
  reverse(f);
  ll left = -1;
  ll right = (ll)pow(10,18)+1;
  while(left < right - 1){
    ll tmp = k;
    ll middle = (left + right)/2;
    rep(i,n){
      if(a[i]*f[i] > middle){
        ll target = a[i]*f[i] - middle;
        tmp -= (target + f[i] - 1)/f[i];
      }
    }//i
    if(tmp < 0) left = middle;
    if(tmp >= 0) right = middle;
  }
  cout << right << endl;
}
