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
  vector<int> A(N),B(N);
  rep(i,N) cin >> A[i] >> B[i];
  vector<pair<int,int>> vec;
  rep(i,N)
  {
    vec.push_back(make_pair(B[i],A[i]));
  }
  sort(RALL(vec));
  int sum = vec[0].first;
  rep(i,N)
  {
    if(sum>vec[i].first)
    {
      sum = vec[i].first;
    }
    sum -= vec[i].second;
    if(sum<0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
