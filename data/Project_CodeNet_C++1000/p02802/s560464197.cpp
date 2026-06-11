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
  int AC = 0;
  int WA = 0;
  vector<int> p(M);
  vector<string> S(M);
  if(M==0)
  {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  rep(i,M) cin >> p[i] >> S[i];
  rep(i,M) p[i] --;
  vector<pair<int,string>> vec(M);
  rep(i,M)
  {
    vec.push_back(make_pair(p[i],S[i]));
  }
  vector<int> ACcount(N,0);
  rep(i,M)
  {
    if(S[i]=="AC"&&ACcount[p[i]]!=-1)
    {
      AC ++;
      WA += ACcount[p[i]];
      ACcount[p[i]] = -1;
    }
    else if(S[i]=="WA"&&ACcount[p[i]]!=-1)
    {
      ACcount[p[i]] ++;
    }
  }
  cout << AC << " " << WA << endl;
  return 0;
}
