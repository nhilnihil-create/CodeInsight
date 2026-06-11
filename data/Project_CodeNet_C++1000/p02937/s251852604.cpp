#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

std::vector<int> pos[26];

int main() {
  std::string s, t; std::cin >> s >> t;
  for(int i = 0; i < s.size(); ++i) pos[s[i]-'a'].push_back(i);

  int n = 0, p = 0;
  int ix[26];
  std::fill_n(ix, 26, 0);
  for(int i = 0; i < t.size(); ++i) {
    int c = t[i] - 'a';
    std::vector<int>& target = pos[c];
    if(target.size() < 1) fin(-1);
    while(ix[c] < target.size() && target[ix[c]] < p) ++ix[c];
    if(ix[c] < target.size()) p = target[ix[c]]+1;
    else {
      ++n;
      std::fill_n(ix, 26, 0);
      p = target[0]+1;
    }
  }
  int64_t ans = (int64_t)n*s.size() + p;
  fin(ans);
  return 0;
}
