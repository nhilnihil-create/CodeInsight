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
  int N,M;
  cin >> N >> M;
  string S;
  cin >> S;
  int now = N;
  stack<int> q;
  rep(i,P)
  {
    if(now<=M)
    {
      q.push(now);
      break;
    }
    rep(j,M)
    {
      if(S[now-M+j]=='0')
      {
        now -= M;
        now += j;
        q.push(M-j);
        break;
      }
      else if(j==M-1)
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  while(!q.empty())
  {
    cout << q.top();
    q.pop();
    if(!q.empty())
    {
      cout << " " ;
    }
    else
    {
      cout << endl;
    }
  }
  return 0;
}
