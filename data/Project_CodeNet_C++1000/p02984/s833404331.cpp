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
  ll N; cin >> N;
  vector<ll> A(N), B(N);
  rep(i, 0, N) cin >> A[i];
  ll sum = 0;
  rep(i, 0, N) sum += A[i];
  for (ll i = 0; i < N - 1; i += 2) {
  	sum -= A[i] * 2;
  }
  B[N - 1] = sum;
  for (ll i = N - 2; i >= 0; i--) {
  	B[i] = A[i] * 2 - B[i + 1];
  }
  rep(i, 0, N) cout << B[i] << " ";
}