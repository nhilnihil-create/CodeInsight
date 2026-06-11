#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

void print_rect(int h, int w)
{
  string s(w, '#');
  for (int i = 0; i < h; ++i) {
    fprintf(stdout, "%s\n", s.c_str());
  }
  return;
}

int main()
{
  int h, w;
  while (true) {
    fscanf(stdin, "%d %d", &h, &w);
    if (h == 0 && w == 0) { break; }
    print_rect(h, w);
    fprintf(stdout, "\n");
  }
  return 0;
}