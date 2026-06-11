// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

/*
1 <= A_i <= 4
A_3 - A_1 = 3 -> 100
A_2 - A_1 = 2 -> 10
A_3 - A_2 = 2 -> 10
1 ? 4
*/
int n, m, q;
typedef tuple<int, int, int, int> P;
vector<P> A;

ll dfs(vector<int> vec) {
  if (vec.size() == n) {
    ll score = 0;
    for (auto &&p: A) {
      int a, b, c, d; tie(a, b, c, d) = p;
      if (vec[b]-vec[a] == c) score += d;
    }
    return score;
  }
  
  ll max_ = 0;
  int start = 1;
  if (vec.size()) start = vec[vec.size()-1];
  loop(i,start,m+1) {
    auto v = vec;
    v.push_back(i);
    max_ = max(max_, dfs(v));
  }
  return max_;
}

int main() {
  cin >> n >> m >> q;
  loop(i,0,q) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--;b--;
    A.emplace_back(a, b, c, d);
  }
  vector<int> v;
  cout << dfs(v) << endl;
  
  return 0;
}
