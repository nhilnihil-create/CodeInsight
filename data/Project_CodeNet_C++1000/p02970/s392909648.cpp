#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n,d;
  cin >> n >> d;
  if(n%(1+d*2) == 0)
    cout << n/(1+d*2)<< endl;
  else
    cout << 1+n/(1+d*2)<< endl;
}