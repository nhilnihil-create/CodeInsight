#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  int A,B;
  cin >> A >> B;
  if(A%2==0&&B%2==1)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else if(A%2==1&&B%2==0)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  for(int i=0;i<1000000001;i++)
  {
    if(abs(A-i)==abs(B-i))
    {
      cout << i << endl;
    }
  }
  return 0;
}
