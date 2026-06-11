#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
int main(){
  int k,x;
  cin >> k >> x;
  x = x - k + 1;
  for(int i = 0; i < k * 2 - 1; i++)cout << x + i << endl;
  return 0;
}
