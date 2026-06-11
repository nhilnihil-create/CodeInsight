#include <bits/stdc++.h>

const int MAX_N = 200005;
int N;
struct rang {
  int st, en;
} rs[MAX_N];

int main() {
  scanf("%d", &N);
  std::vector<int> mm, dd;
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &rs[i].st, &rs[i].en);
    mm.push_back(rs[i].st);
    dd.push_back(rs[i].en);
  }
  std::sort(mm.begin(), mm.end());
  std::sort(dd.begin(), dd.end());
  if (N % 2) {
    int left_lower = mm[mm.size()/2];
    int right_higher = dd[dd.size()/2];
    printf("%d\n", right_higher - left_lower + 1);
  } else {
    int left_lower = (mm[mm.size()/2] + mm[mm.size()/2-1]);
    int right_higher = (dd[dd.size()/2] + dd[dd.size()/2-1]);
    printf("%d\n", right_higher - left_lower + 1);
  }

}
