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

int N;
long long dp[100050];

int main()
{
  cout << fixed << setprecision(10);
  int N,M;
  cin >> N >> M;
  vector<int> a(M);
  rep(i,M) cin >> a[i];
  rep(i,100010) dp[i] = 0;
  rep(i,M) dp[a[i]] = -1;
  dp[0] = 1;
  if(M==0||a[0]!=1)
  {
    dp[1] = 1;
  }
  else
  {
    dp[1] = 0;
  }
  for(int i=2;i<N+1;i++)
  {
    if(dp[i]!=-1)
    {
      dp[i] = dp[i-2] + dp[i-1]; 
    }
    else
    {
      dp[i] = 0;
    }
    dp[i] = dp[i]%P;
  }
  cout << dp[N]%P << endl;
  return 0;
}
