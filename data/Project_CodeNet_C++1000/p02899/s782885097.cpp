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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N)
  {
    cin >> A[i];
  }
  vector<pair<int,int>> vec;
  rep(i,N)
  {
    vec.push_back(make_pair(A[i],i+1));
  }
  sort(ALL(vec));
  rep(i,N)
  {
    if(i!=N-1)
    {
      cout << vec[i].second << " ";
    }
    if(i==N-1)
    {
      cout << vec[i].second << endl;
    }
  }
  return 0;
}
