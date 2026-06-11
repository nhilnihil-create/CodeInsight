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
ll modPow(ll a, ll n, ll p){
  if(!n) return 1;
  if(a == 1) return a % p;
  if(n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}
ll choose(ll n, ll k){
  ll x = 1, y = 1;
  rep(i, k){
    x *= n - i;
    y *= i + 1;
    x %= mod;
    y %= mod;
  }
  y = modPow(y, mod - 2, mod);
  return x * y % mod;
}
int main(){
  int x,y;
  cin >> x >> y;
  int m = (2 * x - y) / 3;
  int n = (2 * y - x) / 3;
  if((x + y) % 3 != 0 || m < 0 || n < 0) cout << 0 << endl;
  else{
    cout << choose(m + n, n) << endl;
  }
}