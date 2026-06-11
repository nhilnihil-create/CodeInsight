#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  ll N,K,S;
  cin >> N >> K >> S;
  if(S>=10000000)
  {
    rep(i,K)
    {
      cout << S << " ";
    }
    rep(i,N-K)
    {
      if(i!=N-K-1)
      {
        cout << 1  << " ";
      }
      else
      {
        cout << 1;
      }  
    }
    cout << endl;
  }
  else
  {
    rep(i,K)
    {
      cout << S << " ";
    }
    rep(i,N-K)
    {
      if(i!=N-K-1)
      {
        cout << 10000000  << " ";
      }
      else
      {
        cout << 10000000;
      }   
    }
    cout << endl;
  }
  return 0;
}
