#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> vec(n, 1);
  for (int i = 0; i <= n; i++)
  {
    if(s[i]==s[i+1]&&s[i]=='R'){
      vec[i + 2] += vec[i];
      vec[i] = 0;
    }
  }
  for (int i = n-1; i >=0;i--){
    if(s[i]==s[i-1]&&s[i]=='L'){
      vec[i - 2] += vec[i];
      vec[i] = 0;
  }
  }
  for (int i = 0; i < n;i++){
    cout << vec[i] << " ";
  }
}