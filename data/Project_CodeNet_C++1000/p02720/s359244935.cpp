#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) (cerr << #x << " = " << x << endl;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

int main()
{
  ios::sync_with_stdio(0);
  int k;
  cin >> k;

  vector<ll>a;

  for(int i = 1; i <= 9 ; i++)
  {
    a.push_back(i);
  }

  while(true)
  {
    if(k < a.size())
    {
      cout << a[k - 1] << endl;
      break;
    } 

    k -= a.size();

    vector<ll>old;
    swap(old, a);
    for(const auto &x : old)
    {
      for(int i = -1; i <= 1; i++)
      {
        int d = x % 10 + i;
        if(d < 0 || d > 9)
          continue;
        a.push_back(x * 10 + d);
      }
    }
  }
  
  return 0;
}