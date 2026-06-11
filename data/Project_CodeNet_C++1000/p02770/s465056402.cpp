#include<bits/stdc++.h>
#define maxn 5005
#define ll long long
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k,q;
	cin >> k >> q;
	for(int i=1;i<=k;i++)
		cin >> arr[i];
	while(q--) {
		int n,x,m;
		cin >> n >> x >> m;
		ll ans = n - 1, rmd = x % m;
		n--;
		for(int i=1;i<=k;i++) {
			int num = n / k + (i <= n % k ? 1 : 0) , val = arr[i] % m;
			rmd = rmd + (ll)val * num;
			ans -= rmd / m;
			rmd %= m;
			if(val == 0)	ans -= num;
		}
		cout << ans << endl;
	}
	return 0;
}
