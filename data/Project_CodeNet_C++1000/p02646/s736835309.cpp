#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define ld long double
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if (W < V && ((ld)abs(B - A) / (V - W)) <= T) {
  	cout << "YES" << endl;
  } else {
  	cout << "NO" << endl;
  }
}
