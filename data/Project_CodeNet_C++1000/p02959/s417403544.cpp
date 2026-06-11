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
int main(){
  int n;
  cin >> n;
  ll ans = 0;
  ll amari = 0;
  vector<ll> a(n + 1), b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n){
    b[i] += amari;
    if(a[i] <= b[i]){
      if(amari >= a[i]) amari = b[i] - amari;
      else amari = b[i] - a[i];
      ans += a[i];
    }else{
      ans += b[i];
      amari = 0;
    }
  }
  ans += min(a[n], amari);
  cout << ans << endl;
}