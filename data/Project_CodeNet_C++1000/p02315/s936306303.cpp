#if 0

#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, W;
int v[110]; int w[110];
int V[110][10010];

int main() {
  cin >> N >> W;
  for (int i = 1; i <= N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i <= N; i++) {
    for (int c = 0; c <= W; c++) {
      if (i == 0 || c == 0)
        V[i][c] = 0;
      else if (c-w[i] < 0)
        V[i][c] = V[i-1][c];
      else
        V[i][c] = max(v[i] + V[i-1][c-w[i]], V[i-1][c]);
    }
  }
  cout << V[N][W] << endl;
}

