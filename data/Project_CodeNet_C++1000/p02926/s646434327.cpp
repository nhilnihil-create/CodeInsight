#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
constexpr double PI = 3.14159265358979;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
struct Data {
  lint x, y;
  double theta;
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<Data> d(N);
  REP(i, N) {
    cin >> d[i].x >> d[i].y;
    d[i].theta = atan2(d[i].y, d[i].x);
  }
  sort(ALL(d), [](auto const &a, auto const &b) { return a.theta < b.theta; });
  REP(i, N) {
    d.push_back(d[i]);
    d[i+N].theta += 2*PI;
  }
  lint ans = 0;
  REP(i, N) {
    lint xsum = 0;
    lint ysum = 0;
    FOR(j, i, i+N) {
      xsum += d[j].x;
      ysum += d[j].y;
      ans = max(ans, xsum*xsum + ysum*ysum);
    }
  }
  cout << fixed << setprecision(10) << sqrt(ans) << "\n";
}