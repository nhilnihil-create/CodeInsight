#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
vector<int> memo;
vector<ll> vec;
ll n;

ll M = 1e6+5;
int main()
{
  
  cin >> n;
  vec.resize(n);
  memo.resize(M, 0);
  for(ll i = 0; i < n; i++) {
    cin >> vec.at(i);
    memo.at(vec.at(i))++;
  }

  bool is_pairwise = true;
  for (int i = 2; i < M; i++) {
    int cnt = 0;
    for (int j = i; j < M; j += i) {
      if (memo.at(j)) cnt += memo.at(j);
    }
    if (cnt > 1) {
      is_pairwise = false;
      break;
    }
  }
  if (is_pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  ll g = 0;
  rep(i,n) g = gcd(g, vec.at(i));
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;

  return 0;
}