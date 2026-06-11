#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  std::string s;
  std::cin >> s;

    vt<std::string> S;
    std::string p,q;
    p += s[0];
    S.push_back(p);
    int tmp = 0;
    for (int i = 1; i < s.size(); ++i) {
      q += s[i];
      if(S[tmp] != q) {
        S.push_back(q);
        q.clear();
        ++tmp;
      }
    }

  std::cout << S.size() << '\n';
  return 0;
}
