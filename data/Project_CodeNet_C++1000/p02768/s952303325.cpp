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
#define mod 1000000007
using ll = long long;
using namespace std;
int modPow(ll a, ll n, ll p) { //繰り返し二乗法 a**n % p
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}
ll choose(ll n, ll k){
  ll num = 1;
  ll waru = 1;
  for(ll i = 0; i < k; i++){
    num *= n - i;
    waru *= i + 1;
    num %= mod;
    waru %= mod;
  }
  waru = modPow(waru, mod - 2, mod);
  return num * waru % mod;
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans = modPow(2, n, mod) - 1;
  ans -= choose(n, a);
  ans -= choose(n, b);
  while(ans < 0) ans += mod;
  cout << ans % mod << endl;
}