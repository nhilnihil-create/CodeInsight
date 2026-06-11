#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

inline void no_ans()
{
  puts("-1");
  exit(0);
}
const int N = 2e5+1;
int A[N], B[N], n;
inline int mod(int i)
{
  return B[(n-1+i)%n] + B[(i+1)%n];
}
set<ii> st;
inline void insert(int i)
{
  if (B[i] > A[i]) st.insert(mp(B[i], i));
}
int main()
{

  while (~scanf("%d", &n))
    {
      ll ans = 0;  
      for (int i = 0; i < n; ++i) scanf("%d", A+i);
      for (int i = 0; i < n; ++i) scanf("%d", B+i);
      for (int i = 0; i < n; ++i) insert(i);
      while (!st.empty())
	{
	  int i = st.rbegin()->second;
	  st.erase(--st.end());
	  int _mod = mod(i);
	  if (_mod > B[i]) no_ans();
	  int old_bi = B[i];
	  if ((B[i]-A[i])%_mod == 0) B[i] = A[i];
	  else
	    {
	      B[i] %= _mod;
	      insert(i);
	    }
	  ans += (old_bi - B[i]) / _mod;
	}
      for (int i = 0; i < n; ++i) if (A[i] != B[i]) no_ans();
      printf("%lld\n", ans);
    }
}
