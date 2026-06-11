#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);

  bool all_0 = true;
  rep(i, n){
    cin >> a[i];
    if(a[i]!=0){
      all_0 = false;
    }
  }

  if(all_0){
    cout << "Yes" << endl;
  }else{

    if(n % 3 != 0){
      cout << "No" << endl;
      return 0;
    }

    map<ll, int> mp;
    rep(i, n){
      mp[a[i]]++;
    }

    if(mp.size() == 3){
      vector<ll> b;
      bool ok = true;
      for(auto p : mp){
        b.push_back(p.first);
        if(p.second != n / 3){
          ok = false;
        }
      }

      if(((b[0] ^ (b[1] ^ b[2])) == 0LL) && ok){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }

    }else if(mp.size()==2){
      
      if(mp[0] == n/3){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }

    }else{
      cout << "No" << endl;
    }

  }

  return 0;
}
