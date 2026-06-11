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
int search(vi &s, int n){
  int left = -1, right = s.size();
  while(left + 1 < right){
    int middle = (left + right) / 2;
    if(s[middle] >= n) right = middle;
    else left = middle;
  }
  return left;
}
int main(){
  int n;
  cin >> n;
  vi l(n);
  rep(i, n) cin >> l[i];
  sort(all(l));
  int ans = 0;
  for(int a = 0; a < n - 2; a++){
    for(int b = a + 1; b < n - 1; b++){
      int num = search(l, l[a] + l[b]);
      if(num != -1 || num != a || num != b) ans += max(0, num - b);
    }
  }
  cout << ans << endl;
}