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
  int N,K;
  cin >> N >> K;
  vector<double> p(N);
  rep(i,N) cin >> p[i];
  rep(i,N)
  {
    p[i] *= 0.5;
    p[i] += 0.5;
  }
  vector<double> rsum(N);
  rsum[0] = p[0];
  rep(i,N-1)
  {
    rsum[i+1] += p[i+1] + rsum[i];
  }
  double M = rsum[K-1];
  double X = M;
  rep(i,N-K)
  {
    X -= p[i];
    X += p[K+i];
    M = max(M,X);
  }
  cout << M << endl;
  return 0;
}