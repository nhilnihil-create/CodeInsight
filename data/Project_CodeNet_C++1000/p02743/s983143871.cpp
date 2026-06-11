#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll A, B, C; cin >> A >> B >> C;
  if ((A + B < C) && (4 * A * B < (C - A - B) * (C - A - B))) {
  	cout << "Yes" << endl;
  } else {
  	cout << "No" << endl;
  }
}