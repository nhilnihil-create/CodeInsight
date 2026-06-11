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
  ll H, W; cin >> H >> W;
  if (H == 1 || W == 1) {
  	cout << 1 << endl;
  }
  else if (H * W % 2) {
  	cout << (H * W + 1) / 2 << endl;
  } else {
  	cout << H * W / 2 << endl;
  }
}