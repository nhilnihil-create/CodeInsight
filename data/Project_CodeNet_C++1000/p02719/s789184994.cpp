#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  ll n, k;cin>>n>>k;
  ll ans = n%k ;
  ll value = min(ans, abs(ans-k));
  cout<< value <<endl;
	return 0;
}

