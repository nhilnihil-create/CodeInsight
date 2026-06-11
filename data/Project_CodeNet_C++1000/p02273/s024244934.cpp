#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Koch
{
public:
  int solve( int x );
  int koch( int n, pair<double, double> p1, pair<double, double> p2, list<pair<double, double> >& rs);
};

int Koch::solve( int x )
{
  list<pair<double, double> > rs;
  koch(x, make_pair(0,0), make_pair(100,0), rs);

  for ( list<pair<double, double> >::iterator it = rs.begin(); it != rs.end(); it++ )
    {
      cout << fixed << setprecision(6) << (*it).first << " " << (*it).second << endl;
    }
  
  return x;
}

int Koch::koch( int n, pair<double, double> p1, pair<double, double> p2, list<pair<double, double> >& rs)
{
  if ( n == 0 )
    {
      rs.push_back(p1);
      rs.push_back(p2);
      return 0;
    }
  
  const double r3 = 1.7320508;
  list<pair<double, double> > rss[4];
  pair<double, double> s = make_pair( (p1.first * 2.0 + p2.first) / 3.0, (p1.second * 2.0 + p2.second) / 3.0 );
  pair<double, double> t = make_pair( (p2.first * 2.0 + p1.first) / 3.0, (p2.second * 2.0 + p1.second) / 3.0 );

  double vx = t.first - s.first;
  double vy = t.second - s.second;

  double rvx = (vx - r3 * vy) / 2.0;
  double rvy = (r3 * vx + vy) / 2.0;
  
  pair<double, double> u = make_pair( s.first + rvx, s.second + rvy );
  
  koch( n-1, p1, s, rss[0] );
  koch( n-1, s,  u, rss[1] );
  koch( n-1, u,  t, rss[2] );
  koch( n-1, t, p2, rss[3] );

  for ( int i = 0; i < 4; i++ )
    {
      if ( i ) rss[i].pop_front();
      for ( list<pair<double, double> >::iterator it = rss[i].begin(); it != rss[i].end(); it++ )
        {
          rs.push_back(*it);
        }
    }
  
  return 0;
}


int main()
{
  int x;

  Koch k;

  cin >> x;

  k.solve( x );

  return 0;
}