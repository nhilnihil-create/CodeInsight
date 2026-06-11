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

ll v[3];

int idx(char x)
{
  if(x == 'R')
    return 0;
  else if(x == 'G')
    return 1;
  else
    return 2;
}


int main()
{
  ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0; i < n ; i++)
  {
    v[idx(s[i])]++;
  }

  ll ans = v[0] * v[1] * v[2];
  for(int i = 0; i < n; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      int k = 2*j - i;
      if(k < n && s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
        ans--;
    }
  }
  cout << ans << endl;
  return 0;
}