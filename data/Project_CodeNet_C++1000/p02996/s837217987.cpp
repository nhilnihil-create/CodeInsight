#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
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
#include <cmath>
#include <numeric>
#include <float.h>
#include <math.h>
using namespace std;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()

typedef unsigned long long ll;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> c(N);//配列の宣言
for(int i = 0; i < N ; i++){
  int a,b;
  cin >> a >> b;
  c[i] = make_pair(b,a);//配列型のpairに代入
}
  sort(c.begin(),c.end());//pair.firstを小さい順にsort
  int sum = 0;
  bool ans = true;
  rep(i,N){
        sum+= c[i].second;
        if(sum > c[i].first){
            ans = false;
            break;
        }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}

