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
int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  int count = 0;
  vi ans(n, 0);
  for(int i = n; i > 0; i--){
    int cnt = 0;
    for(int j = i + i; j <= n; j += i) cnt += ans[j - 1];
    int num = (a[i - 1] ^ cnt) & 1;
    ans[i - 1] = num;
    if(num) count++;
  }
  cout << count << endl;
  rep(i, n){
    if(ans[i]){
      count--;
      cout << i + 1;
      if(!count) cout << endl;
      else cout << " ";
    }
  }
}