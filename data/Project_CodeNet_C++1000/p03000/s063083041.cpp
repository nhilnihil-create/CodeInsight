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

int sum(int n)
{
  if(n == 0)
  {
    return 0;
  }
  int s = sum(n-1);
  return s + n;
}
int main()
{
  cout << fixed << setprecision(10);
  int N,X;
  cin >> N >> X;
  vector<int> L(N),vec(N+1);
  rep(i,N)
  {
    cin >> L[i];
  }
  int su = 0;
  rep(i,N)
  {
    su += L[i];
    vec[i+1] = su;
  }
  int count = 0;
  rep(i,N+1)
  {
    if(vec[i]<=X)
    {
      count ++;
    }
  }
  cout << count << endl;
  return 0;
}
