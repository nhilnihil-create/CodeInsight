#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

int N, M, A, B;
int mp[1003][1003];

int main() {
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
  scanf("%d%d%d%d", &N, &M, &A, &B);
  for (int i = 1; i <= A; i++) mp[1][i] = 1;
  for (int i = A + 1; i <= M; i++) mp[1][i] = 0;
  for (int i = 2; i <= B; i++) memcpy(mp[i], mp[1], sizeof(mp[1]));
  for (int i = 1; i <= A; i++) mp[B + 1][i] = 0;
  for (int i = A + 1; i <= M; i++) mp[B + 1][i] = 1;
  for (int i = B + 1; i <= N; i++) memcpy(mp[i], mp[B + 1], sizeof(mp[B + 1]));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) printf("%d", mp[i][j]);
    putchar('\n');
  }
  return 0;
}
