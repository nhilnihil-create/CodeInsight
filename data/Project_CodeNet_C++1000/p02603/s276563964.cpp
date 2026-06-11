#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  ll f = 0, n, m = 1000, x, y, i, j, st = 0;
  cin >> n;
  int a[n + 23];
  for (i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (i = 2; i <= n; i++)
  {
    if (a[i] > a[i - 1])
    {
      if (f == 0)
      {
        st = m / a[i - 1];
        m = m % a[i - 1];
      }
      f = 1;
    } else if (a[i] < a[i - 1])
    {
      if (f == 1)
      {
        m += st * a[i-1];
        st = 0;
      }
      f = 0;
    }
    if (i == n)
    {
      m += st * a[i];
    }
  }
  cout << m << endl;
}