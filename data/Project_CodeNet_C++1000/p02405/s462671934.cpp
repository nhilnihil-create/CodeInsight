#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  int h, w;
  while (true) {
    fscanf(stdin, "%d %d", &h, &w);
    if (h == 0 && w == 0) { break; }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if ((i + j) % 2 == 0) {
          printf("#");
        }
        else { printf("."); }
      }
      fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
  }
  return 0;
}