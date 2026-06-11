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
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
ll gcd(ll a, ll b){
  if(a % b == 0) return b;
  return gcd(b, a % b);
}
int main(){
  ll a,b;
  cin >> a >> b;
  ll num = a;
  map<ll, int> cnt;
  for(int i = 2; i <= sqrt(a); i++){
    if(num % i == 0){
      num /= i;
      cnt[i]++;
    }
    while(num % i == 0) num /= i;
  }
  if(num > 1) cnt[num]++;
  num = b;
  for(int i = 2; i <= sqrt(b); i++){
    if(num % i == 0){
      num /= i;
      cnt[i]++;
    }
    while(num % i == 0) num /= i;
  }
  if(num > 1) cnt[num]++;
  int ans = 1;
  for(auto x : cnt){
    if(x.second == 2) ans++;
  }
  cout << ans << endl;
}