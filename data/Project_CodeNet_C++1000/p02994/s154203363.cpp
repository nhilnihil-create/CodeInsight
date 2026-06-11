#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,L;
	cin >> N >> L;

	vector<pair<int,int>> v(N);
	rep(i,N){
		v[i].second = L + i;
		v[i].first = abs(v[i].second);
	}

	sort(v.begin(),v.end());

	int ans = 0;
	repk(i,1,N){
		ans += v[i].second;
	}
	cout << ans << endl;
	return 0;
}