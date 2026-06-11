#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "


int n;
set<int> pos;
map<int, int> cnt;
vector<int> buf;
void go(int cur)
{
  //  cerr << "go " << cur << endl;
  for (;;)
    {
      cur <<= 1;
      if (cur < (1<<(n+1))) buf.pb(cur|1);//, cerr << "add " << (cur|1) << endl;
      else break;
    }
}
  
void solve()
{
  pos.clear();
  cnt.clear();
  pos.insert(1);
  for (int i = 0; i < (1<<n); ++i)
    {
      int u; scanf("%d", &u);
      ++cnt[-u];
    }
  for (auto e : cnt)
    {
      if (pos.size() < e.second)
	{
	  //	  cerr << "insert " << -e.first << " fail expected = " << e.second << " actual = " << pos.size() << endl;
	  puts("No");
	  return;
	}
      for (int i = 0; i < e.second; ++i)
	{
	  int cur = *pos.begin();
	  pos.erase(pos.begin());
	  go(cur);
	}
      for (auto e : buf) pos.insert(e);
      buf.clear();
    }
  puts("Yes");
}
int main()
{

  while (~scanf("%d", &n)) solve();


}
