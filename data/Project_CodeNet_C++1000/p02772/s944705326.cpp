#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) (cerr << #x << " = " << x << endl;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c)

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
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
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++)
  {
    int a;
    cin >> a;
    if(a  %2 == 0)
    {
      if((a % 3 != 0) && (a % 5 != 0))
      {
        cout << "DENIED\n";
        return 0;
      }
    }
  }

  cout << "APPROVED" << endl;
  return 0;
}