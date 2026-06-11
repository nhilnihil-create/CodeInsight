#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  int id = 0;
  int ids[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) { ids[i][j] = ids[j][i] = id++; }
  }

  int M = N * (N - 1) / 2;
  int indegrees[M];
  std::vector<std::vector<int> > s2t(M);
  for (int i = 0; i < M; i++) { indegrees[i] = 0; }

  for (int i = 0; i < N; i++) {
    int s, j;
    std::cin >> j;
    j--;
    s = ids[i][j];

    for (int _ = 0; _ < N - 2; _++) {
      std::cin >> j;
      j--;
      int t = ids[i][j];
      s2t[s].push_back(t);
      indegrees[t]++;
      s = t;
    }
  }

  std::vector<int> topolo_order;
  std::stack<int> st1, st2;
  for (int i = 0; i < M; i++)
    if (indegrees[i] == 0) st1.push(i);

  int cnt = 0;
  auto sta = &st1;
  auto stb = &st2;
  do {
    while (sta->size() > 0) {
      int i = sta->top();
      sta->pop();
      topolo_order.push_back(i);
      // std::cout << i << ", ";
      while (s2t[i].size() > 0) {
        int j = s2t[i].back();
        s2t[i].pop_back();
        indegrees[j]--;
        if (indegrees[j] == 0) stb->push(j);
      }
    }
    auto tmp = sta;
    sta = stb;
    stb = tmp;
    cnt++;
    // std::cout << " : " << cnt << std::endl;
  } while (sta->size() > 0);

  if (topolo_order.size() != M) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << cnt << std::endl;
  }
}
