#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <deque>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int h, w;
int w_ans[2001][2001];
int h_ans[2001][2001];

vector<string> sw;
vector<string> sh;

bool grid_inside(int y, int x) {
  if(0 <= y && y < h && 0 <= x && x < w) return true;
  else return false;
}

int rec_h(int i, int j, int c) {
  if(!grid_inside(i, j)) return c;
  if(sh[i][j] == '#') return c;
  sh[i][j] = '#';
  c++;
  h_ans[i][j] = rec_h(i + 1, j, c);
  return h_ans[i][j];
}

int rec_w(int i, int j, int c) {
  if(!grid_inside(i, j)) return c;
  if(sw[i][j] == '#') return c;
  sw[i][j] = '#';
  c++;
  w_ans[i][j] = rec_w(i, j + 1, c);
  return w_ans[i][j];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  REP(i, h) {
    string s;
    cin >> s;
    sw.push_back(s);
    sh.push_back(s);
  }

  REP(i, h) {
    REP(j, w) {
      if(sh[i][j] == '.') rec_h(i, j, 0);
      if(sw[i][j] == '.') rec_w(i, j, 0);
    }
  }

  int ans = 0;
  REP(i, h) REP(j, w) {
    ans = max(ans, h_ans[i][j] + w_ans[i][j] - 1);
  }
  cout << ans << endl;
}
