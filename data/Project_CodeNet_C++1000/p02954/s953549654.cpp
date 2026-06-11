#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define prvsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
#define ll long long
#define ld long double
#define fixset(val) fixed << setprecision(10) << val 
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  string S; cin >> S;
  ll N = S.size();
  vector<ll> A(N, 0);
  ll a = 0, b, c;
  rep(i, 0, N) {
  	if (S.substr(i, 2) == "RL") {
    	b = i;
    }
    if (i == N - 1 || S.substr(i, 2) == "LR") {
    	c = i;
      	if ((c - a + 1) % 2 == 0) {
        	A[b] = (c - a + 1) / 2;
          	A[b + 1] = A[b];
        } else if ((b - a + 1) % 2 == 1){
        	A[b + 1] = (c - a + 1) / 2;
          	A[b] = A[b + 1] + 1;
        } else {
        	A[b] = (c - a + 1) / 2;
          	A[b + 1] = A[b] + 1;
        }
      	if (i < N - 1) a = i + 1;     	
    }
  }
  rep(i, 0, N) {
  	cout << A[i] << " ";
  }
}