#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int modPow(ll a, ll n, ll p) { //繰り返し二乗法 a**n % p
  if(!n) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, 60){
    ll num = (1LL << i);
    ll cnt = 0;
    rep(j, n) if(num & a[j]) cnt++;
    ll v = (cnt * (n - cnt)) % mod;
    (v *= num % mod) %= mod;
    ans += v;
    ans %= mod;
  }
  cout << ans << endl;
}