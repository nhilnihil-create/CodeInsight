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
  int h,w;
  cin >> h >> w;
  vvi board(h, vi(w));
  rep(i, h){
    rep(j, w){
      char s;
      cin >> s;
      board[i][j] = (s == '#') ? 0 : 1;
    }
  }
  vvi left(h, vi(w)), right(h, vi(w)), up(h, vi(w)), down(h, vi(w));
  rep(y, h){
    left[y][0] = board[y][0];
    right[y][w - 1] = board[y][w - 1];
    rep(x, w){
      if(!y){
        up[0][x] = board[0][x];
        down[h - 1][x] = board[h - 1][x];
      }else{
        if(!board[y][x]) up[y][x] = 0;
        else up[y][x] = up[y - 1][x] + 1;

        if(!board[h - 1 - y][x]) down[h - 1 - y][x] = 0;
        else down[h - 1 - y][x] = down[h - y][x] + 1;
      }
      if(x){
        if(!board[y][x]) left[y][x] = 0;
        else left[y][x] = left[y][x - 1] + 1;

        if(!board[y][w - 1 - x]) right[y][w - 1 - x] = 0;
        else right[y][w - 1 - x] = right[y][w - x] + 1;
      }
    }
  }
  int ans = 0;
  rep(y, h){
    rep(x, w){
      if(board[y][x]){
        int num = right[y][x] + left[y][x] + up[y][x] + down[y][x] - 3;
        ans = max(ans, num);
      }
    }
  }
  cout << ans << endl;
}