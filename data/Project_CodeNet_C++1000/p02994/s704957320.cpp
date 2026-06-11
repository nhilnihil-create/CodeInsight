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
  int N,L;
  cin >> N >> L;
  vector<int> vec(N);
  int unreal , real = 0;
  vector<int> vecexcept(N);
  rep(i,N)
  {
    vec[i] = L + i;
  }
  rep(i,N)
  {
    unreal += vec[i];
  }
  rep(i,N)
  {
    vecexcept[i] = unreal -vec[i];
  }
  int m = 2222;
  rep(i,N)
  {
    m = min(abs(unreal - vecexcept[i]),m);
  }
  rep(i,N)
  {
    if(abs(unreal - vecexcept[i])==m)
    {
      cout << vecexcept[i] << endl;
      break;
    }
  }
  return 0;
}
