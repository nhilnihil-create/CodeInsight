#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50 + 3;
const int max_len = 100 + 3;

char name[maxn][max_len];
int n, period[maxn];
char bufname[max_len];

inline bool is_equal(int idx) {
  if (strlen(name[idx] + 1) != strlen(bufname + 1)) return false;
  for (int i = 1; i <= strlen(name[idx] + 1); i++)
    if (bufname[i] != name[idx][i]) return false;
  return true;
}

int solve() {
  int ans = 0, idx;
  for (idx = 1; !is_equal(idx); ++idx);
  for (int i = idx + 1; i <= n; i++) ans += period[i];
  return ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  while (~scanf("%d", &n)) {
    memset(name, 0, sizeof(name));
    memset(bufname, 0, sizeof(bufname));
    for (int i = 1; i <= n; i++)
      scanf("%s%d", name[i] + 1, &period[i]);
    scanf("%s", bufname + 1);
    printf("%d\n", solve());
  }
  return 0;
}
