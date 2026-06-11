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

#define fi(a) for (ll i = 0; i < a; ++i)
#define fid(a) for (ll i = a; i >= 0; --i)
#define fjd(a) for (ll j = a; j >= 0; --j)
#define fj(a) for (ll j = 0; j < a; ++j)
#define rep(i, a, b) for (ll i = (a); ll <= int(b); ll++)


ll n,m,K;

bool issafe(int x,int y) {
	return (x>=0 && x < n) && (y>=0 && y<m);
}


int main() {

	cin >> n;
	string result;
	while(n > 0) {
		n -= 1;
		result.push_back('a' + n%26);
		n /= 26;
	}
	reverse(result.begin(),result.end());
	cout << result << endl;
// 664 B
/*	int sx,sy;
	cin >> n >> m >> sx >> sy;
	--sx,--sy;
	vector<vector<bool>> vis(n,vector<bool>(m,-1));
	for(int i = sy;i < m;i++)
		cout << sx+1 << " " << i+1 << endl;

	for(int i = sy-1;i >= 0;i--)
		cout << sx+1 << " " << i+1 << endl;
	sy = 0;
	for(int i = 0; i < n;i++) {
		if(i != sx) {
			if(sy == 0) {
				for(int j = 0;j < m;j++)
					cout << i+1 << " " << j+1 << endl;
				sy = m-1;
			}
			else {
				for(int j = m-1;j >=0;j--)
					cout << i+1 << " " << j+1 << endl;
				sy = 0;
			}
		}
	}*/
// 664 C
/*	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i = 0;i<n;i++)
		cin >> a[i];
	for(int j = 0;j <m;j++)
		cin >> b[j];
	ll min_val = INT_MAX;
	ll  A = 0;
	for(A = 0;A < (1<<9);A++ )
	{
		ll count = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				auto c = a[i]&b[j];
				if((A|c) == A)
				{
					count++;
					break;
				}
			}
		}
		if(count == n)
			break;
	}
	cout << A << endl;
*/
// 664 A
/*	int t;
	cin >> t;
	while(t--) {
		ll r,g,b,w;
		cin >> r >> g >> b >> w;
		auto min_value = min(r,min(g,b));
		int rgb_count = (r%2) + (g%2) + (b%2) + (w%2);
		if(rgb_count <= 1)
			cout << "Yes" << endl;
		else if(r > 0 && g > 0 && b > 0  && (((r-1)%2 +(g-1)%2+(b-1)%2+(w+1)%2) <=1 ))
			cout << "Yes" << endl;
		else
			cout << "No" <<  endl;

	}*/
	return 0;
}	