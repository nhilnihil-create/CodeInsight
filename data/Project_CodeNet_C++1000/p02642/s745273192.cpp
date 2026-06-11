#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
ll mod(ll x) {
	return (x%MOD + MOD) %MOD;
}
ll mul(ll a,ll b) {
	return mod(mod(a) * mod(b));
}

int main() {
	int n;
	cin >> n;
	int m = 1e6+1;
	vector<int> cnt(m,0);
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	
	for(int i = 0 ; i < n; i++)
	{
		auto tmp = v[i];
		if(cnt[tmp] == 0) {
			for(int j = tmp;j < m ; j += tmp)
				cnt[j]++;
		}
		else
			cnt[tmp] = 2;
	}

	int result = 0;
	for(auto i : v)
		if(cnt[i] == 1)
			result++;
	cout << result << endl;
}