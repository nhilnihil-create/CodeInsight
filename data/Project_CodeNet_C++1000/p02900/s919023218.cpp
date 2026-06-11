#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline int isPrime(ll n){
  for(ll i = 2; i*i <= n; i++) if(n % i == 0) return 0;
  return 1;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll a,b; cin >> a >> b;

  ll gcd = __gcd(a,b);
  int ans = 0;
  for(ll i = 1; i*i <= gcd; i++){
    if(gcd % i == 0){
      ans += isPrime(i);
      if(i != gcd/i) ans += isPrime(gcd/i);
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
