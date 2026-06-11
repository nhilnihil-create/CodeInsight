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
#define all(a) (a).begin()+1, (a).end()
#define mod 2019
using ll = long long;
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  vi changed, ans(n);
  rep(i, n - 1){
    if(s[i] == 'R' && s[i + 1] == 'L'){
      changed.push_back(i);
      ans[i]++;
      ans[i + 1]++;
    }
  }
  changed.push_back(n);
  int before = 0;
  for(int i : changed){
    for(int j = before; j < i; j++){
      if(s[j] == 'L'){
        if((j - before) & 1){
          ans[before - 1]++;
        }else ans[before - 2]++;
      }else{
        if((i - j) & 1){
          ans[i + 1]++;
        }else ans[i]++;
      }
    }
    before = i + 2;
  }
  rep(i, n - 1) cout << ans[i] << " ";
  cout << ans[n - 1] << endl;
}