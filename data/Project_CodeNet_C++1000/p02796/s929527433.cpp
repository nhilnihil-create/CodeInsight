#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> P;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int main(void) {
  vector<P> robots;
  int N;
  cin >> N;
  rep(i, N) {
    int x, l;
    cin >> x >> l;
    robots.push_back(P(x + l, x - l));
  }

  Sort(robots);

  int count = 0;
  int before = 0;
  rep(i, N) {
    P p = robots[i];
    if (count == 0 || before <= p.second) {
      count++;
      before = p.first;
    }
  }

  cout << count << endl;

  return 0;
}