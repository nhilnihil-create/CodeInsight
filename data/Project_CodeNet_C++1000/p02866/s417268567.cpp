#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
	const ll mod = 998244353;
    int n; cin >> n;
	int mx = 0;
	vector<int> v(n);
	map<int, int> m;
	rep(i, n) {
		cin >> v[i];
		m[v[i]]++;
		mx = max(mx, v[i]);
	}
	if(v[0] != 0){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	sort(All(v), greater<int>());
	for(int i = 0; i < n-1; i++){
		ans *= m[v[i]-1];
		ans %= mod;
	}
	cout << ans << endl;

    system("pause");
}
