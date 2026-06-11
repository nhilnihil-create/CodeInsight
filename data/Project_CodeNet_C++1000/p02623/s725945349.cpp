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

ll bs(vector<ll> &v,ll l,ll r,ll key) {
	//cout << low << " " << high << endl;
	while (r - l > 1) { 
	       int m = (l + r)/ 2; 
	       if (v[m] >= key) 
	           r = m; 
	       else
	           l = m; 
	   } 
	 
	return (v[r] > key)?l:r; 
}
int main() {
	int n,m,k;
	cin >> n >> m >> k;
	vector<ll> a(n+1);
	vector<ll> b(m+1);
	ll sum = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		a[i] += sum;
		sum = a[i];
	}
	sum = 0;
	for(int i = 1;i<=m;i++) {
		cin >> b[i];
		b[i] += sum;
		sum = b[i];
	}
	ll j = m;
	ll result = 0;
	for(int i = 0; i <=n && a[i] <= k ;i++)
	{
		j = bs(b,0,j,(k-a[i]));
		if(j == -1) break;
		result = max(result,i+j);
	}
	cout << result << endl;
	return 0;
}
