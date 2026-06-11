#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;

  /* 文字列の結果を格納 */
  std::vector<std::pair<std::string, char> > res; /* 文字列, 文字列中の文字の最大値 a~j, 0~9に対応 */

  /* 長さ1の標準形aを代入 */
  res.push_back(std::pair<std::string, char>("a", 'a'));

  /* n-1回繰り返す */
  while (--n) {

    /* 仮の結果 */
    std::vector<std::pair<std::string, char> > res_tmp;

    for (auto p : res) {
      std::string s = p.first; // 現在の文字列
      char mx = p.second;       // 文字列中の最大値

      /* 現在のlen(標準形)+1の長さの標準形を作る */
      for (char c = 'a'; c <= mx + 1; ++c) {
        std::string s_tmp = s + c; 
        char mx_tmp = std::max(c, mx); // mx以上 
        res_tmp.push_back(std::pair<std::string, char>(s_tmp, mx_tmp));
      }
    } 

    res = res_tmp;
  }

  /* 昇順でソート */
  std::sort(res.begin(), res.end());
  
  for (auto p : res) {
    std::cout << p.first << std::endl;
  }

  return 0;
}
