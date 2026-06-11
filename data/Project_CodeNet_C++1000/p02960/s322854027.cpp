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
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(13));
  dp[0][0] = 1;
  rep(i, n){
    int a;
    if(s[i] == '?') a = -1;
    else a = s[i] - '0';
    if(a == -1){
      rep(j, 10){
        rep(k, 13){
          (dp[i + 1][(k * 10 + j) % 13] += dp[i][k]) %= mod;
        }
      }
    }else{
      rep(k, 13){
        (dp[i + 1][(k * 10 + a) % 13] += dp[i][k]) %= mod;
      }
    }
  }
  cout << dp[n][5] << endl;
}