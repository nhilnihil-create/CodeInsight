#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main() {
  ll n; cin >> n;
  ll cnt=0;
  
  for(int i=1; i<n+1; i++){
    if(GetDigit(i)%2 == 1)
      cnt++;
  }
  cout << cnt << endl;
}