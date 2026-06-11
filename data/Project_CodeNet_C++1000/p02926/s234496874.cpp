#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

ll product(l4 a, l4 b)
{
  return a.first*b.second-a.second*b.first;
}
ll len(l4 a)
{
  return a.first * a.first + a.second * a.second;
}
int main()
{
  int n;
  while (~scanf("%d", &n))
    {
      vector<l4> v(n);
      for (auto &e : v) scanf("%lld %lld", &e.first, &e.second);
      sort(v.begin(), v.end(), [&](const ii &l, const ii &r)
			       {
				 return atan2(l.second, l.first) < atan2(r.second, r.first);
			       });
      v.insert(v.end(), v.begin(), v.end());
      /*      cerr << v.size() << endl;
      for (auto e : v)
	cerr << e.first << ", " << e.second << endl;
      cerr << endl;
      */
      ll ans = 0;
      int r = 0;
      l4 sum(0, 0);
      auto update = [&]()
		    {
		      ans = max(ans, len(sum));
		    };
      for (int i = 0; i < n; ++i)
	{
	  sum = mp(0, 0);
	  for (int j = i; j < i+n; ++j)
	    {
	      sum.first += v[j].first;
	      sum.second += v[j].second;
	      update();
	    }
	}
      printf("%.10lf\n", sqrt(ans));
    }
}
