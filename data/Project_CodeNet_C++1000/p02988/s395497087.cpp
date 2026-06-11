#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 5000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> p(n);
	rep(i,n){
		cin >> p[i];
	}

	for(int i=0; i<=(n-3); i++){
		vector<int> v(3);
		v[0] = p[i];
		v[1] = p[i+1];
		v[2] = p[i+2];
		sort(v.begin(),v.end());

		if(v[1] == p[i+1]){
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
