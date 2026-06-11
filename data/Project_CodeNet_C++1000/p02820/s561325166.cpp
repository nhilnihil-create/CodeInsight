#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  int N,K,R,S,P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  int sum = 0;
  rep(i,K)
  {
    if(T[i]=='r')
    {
      sum += P;
    }
    else if(T[i]=='s')
    {
      sum += R;
    }
    else
    {
      sum += S;
    }   
  }
  for(int i=K;i<N;i++)
  {
    if(T[i]=='r')
    {
      if(T[i-K]=='r')
      {
        T[i] = '0';
        continue;
      }
      else
      {
        sum += P;
      }
    }
    else if(T[i]=='s')
    {
      if(T[i-K]=='s')
      {
        T[i] = '0';
        continue;
      }
      else
      {
        sum += R;
      }
    }
    else if(T[i]=='p')
    {
      if(T[i-K]=='p')
      {
        T[i] = '0';
        continue;
      }
      else
      {
        sum += S;
      }      
    }
    
  }
  cout << sum << endl;
  return 0;
}
