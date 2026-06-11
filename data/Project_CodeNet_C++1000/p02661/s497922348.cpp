//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n, greater<ll>());
	if(n & 1){
		cout << b[n / 2] - a[n / 2] + 1;
		return 0;
	}
	cout << b[n / 2 - 1] + b[n / 2] - a[n / 2 - 1] - a[n / 2] + 1;
	
	return 0;
}
