#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum(ll x){
	return (x * (x + 1) / 2) % (int)(1e9 + 7);
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int before = 0, after = 0;
		for (int j = i - 1; j >= 0; j--){
			if(a[j] < a[i]){
				before++;
			}
		}
		for (int j = i + 1; j < n; j++){
			if(a[j] < a[i]){
				after++;
			}
		}
		ans += (sum(k - 1) * before + sum(k) * after) % (int)(1e9 + 7);
		ans %= (int)(1e9 + 7);
	}
	cout << ans << endl;
}
