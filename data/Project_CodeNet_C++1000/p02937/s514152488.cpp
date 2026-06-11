#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using vi = vector<int>;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

int main() {
  string S, T;
  ins(S, T);

  map<char, vi> m_s;
  rep(i, S.size())
    m_s[S[i]].push_back(i);

  int idx = -1;
  int n = 0;
  rep(i, T.size()) {
    if (m_s.count(T[i]) == 0) {
      cout << "-1\n";
      return 0;
    }
    auto it = all(upper_bound, m_s[T[i]], idx);
    if (it == m_s[T[i]].end()) {
      ++n;
      idx = m_s[T[i]][0];
    } else
      idx = *it;
  }
  cout << 1LL * idx + n*S.size() + 1 << endl;

  return 0;
}
