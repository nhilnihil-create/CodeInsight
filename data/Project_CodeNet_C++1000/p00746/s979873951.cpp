#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
typedef pair<int, int> pii;

int N;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main(void) {
  while(cin >> N, N) {
    int minx = 0, maxx = 1;
    int miny = 0, maxy = 1;
    vector<pii> v;
    v.push_back(pii(0, 0));
    REP(i, 0, N - 1) {
      int n, d;
      cin >> n >> d;
      int nx = v[n].first + dx[d];
      int ny = v[n].second + dy[d];
      minx = min(minx, nx);
      maxx = max(maxx, nx + 1);
      miny = min(miny, ny);
      maxy = max(maxy, ny + 1);
      v.push_back(pii(nx, ny));
    }
    cout << (maxx - minx) << " " << (maxy - miny) << endl;
  }
}