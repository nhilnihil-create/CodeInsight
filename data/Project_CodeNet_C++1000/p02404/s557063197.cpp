#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

void print_frame(int h, int w)
{
  string border(w, '#');
  string s;
  if (w > 1) {
    s = string(1, '#') + string(max(0, w - 2), '.') + string(1, '#');
  }
  else {
    s = string(1, '#');
  }
  fprintf(stdout, "%s\n", border.c_str());
  for (int i = 0; i < h - 2; ++i) {
    fprintf(stdout, "%s\n", s.c_str());
  }
  if (h > 1) {
    fprintf(stdout, "%s\n", border.c_str());
  }
  return;
}

int main()
{
  int h, w;
  while (true) {
    fscanf(stdin, "%d %d", &h, &w);
    if (h == 0 && w == 0) { break; }
    print_frame(h, w);
    fprintf(stdout, "\n");
  }
  return 0;
}