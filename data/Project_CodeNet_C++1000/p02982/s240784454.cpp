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
  int n,d;
  cin >> n >> d;
  vvi x(n, vi(d));
  rep(i, n){
    rep(j, d) cin >> x[i][j];
  }
  int ans = 0;
  rep(i, n - 1){
    for(int j = i + 1; j < n; j++){
      int num = 0;
      rep(k, d) num += pow(x[i][k] - x[j][k], 2);
      double val = sqrt(num);
      if(val - (int)val == 0) ans++;
    }
  }
  cout << ans << endl;
}