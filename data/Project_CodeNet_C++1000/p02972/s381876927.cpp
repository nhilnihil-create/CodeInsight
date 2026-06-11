#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N, M = 0; cin >> N;
  vector<ll> A(N + 1), box(N + 1, 0);
  A[0] = 0;
  rep(i, 1, N + 1) cin >> A[i];
  for (ll i = N; i > 1; i--) {
    box[i] = A[i];
  	for (ll j = 2; i * j <= N; j++) {
    	box[i] ^= box[i * j];
    }
    if (box[i]) M++;
  }
  box[1] = (M % 2) ^ A[1];
  if (box[1]) M++;
  cout << M << endl;
  rep(i, 1, N + 1) {
  	if (box[i]) cout << i << " ";
  }
}
