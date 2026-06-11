#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

void rec(pair<double, double> p1, pair<double, double> p2, int depth, vector<pair<double, double> >& v)
{
  if (depth <= 0) {
    v.push_back(p2);
    return;
  }
  pair<double, double> s, t, u;
  s.first = p1.first + (p2.first - p1.first) / 3;
  s.second = p1.second + (p2.second - p1.second) / 3;
  t.first = p1.first + (p2.first - p1.first) * 2 / 3;
  t.second = p1.second + (p2.second - p1.second) * 2 / 3;
  double x = t.first - s.first, y = t.second - s.second;
  u.first = x / 2 - sqrt(3) * y / 2 + s.first;
  u.second = sqrt(3) * x / 2 + y / 2 + s.second;
  //fprintf(stderr, "DEBUG: u=(%lf, %lf)\n", u.first, u.second);
  rec(p1, s, depth - 1, v);
  rec(s, u, depth - 1, v);
  rec(u, t, depth - 1, v);
  rec(t, p2, depth - 1, v);
}

int main()
{
  int n = 0;
  fscanf(stdin, "%d", &n);
  pair<double, double> p1 = make_pair(0, 0);
  pair<double, double> p2 = make_pair(100, 0);
  vector<pair<double, double> > v;
  v.push_back(p1);
  rec(p1, p2, n, v);
  for (int i = 0; i < v.size(); ++i) {
    fprintf(stdout, "%.6lf %.6lf\n", v[i].first, v[i].second);
  }
  return 0;
}