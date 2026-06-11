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
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  priority_queue<int> pr;
  rep(i,N)
  {
    pr.push(A[i]);
  }
  rep(i,M)
  {
    int MAXIMUM = pr.top() / 2;
    pr.pop();
    pr.push(MAXIMUM);
  }
  ll sum = 0;
  rep(i,N)
  {
    sum += pr.top();
    pr.pop();
  }
  cout << sum << endl;
  return 0;
}
