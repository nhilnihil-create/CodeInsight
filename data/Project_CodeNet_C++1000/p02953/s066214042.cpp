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
  vector<int> H(N);
  rep(i,N)
  {
    cin >> H[i];
  }
  bool ans = true;
  for(int i=N-1;i>0;i--)
  {
    if(H[i]<H[i-1])
    {
      H[i-1] -= 1;
      if(H[i]<H[i-1])
      {
        ans = false;
      }
    }
  }
  if(ans == true)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  return 0;
}
