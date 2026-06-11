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
  int N;
  cin >> N;
  vector<int> p(N),q(N);
  int count = 0;
  rep(i,N)
  {
    cin >> p[i];
    q[i] = i + 1;
  }
  rep(i,N)
  {
    if(p[i]!=q[i])
    {
      count ++;
    }
  }
  if(count==0||count==2)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
