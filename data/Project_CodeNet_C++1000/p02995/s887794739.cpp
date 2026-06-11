#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  ll a, b, c, d;
  cin>>a>>b>>c>>d;
  ll x, i, j, k;
  x = (c*d)/__gcd(c, d);
  if(a%c == 0)
  {
     i = b/c - a/c + 1;
  }
  else if(a%c != 0)
  {
      i = b/c - a/c;
  }
  if(a%d == 0)
  {
      j = b/d - a/d + 1;
  }
  else if(a%d != 0)
  {
      j = b/d - a/d;
  }

  if(a%x == 0)
  {
      k = b/x - a/x + 1;
  }
  else if(a%x != 0)
  {
      k = b/x - a/x;
  }

  cout<<b - a - i - j + k + 1<<endl;



return 0;
}

