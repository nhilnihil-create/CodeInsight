#include <bits/stdc++.h>


using namespace std;

typedef long long int ll;

int main(){
	int n,m;
	ll k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i!=0) a[i] += a[i-1];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
		if(i!=0) b[i] += b[i-1];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ll rem = k - a[i];
		if(rem < 0) break;
		int can = upper_bound(b.begin(),b.end(),rem) - b.begin();
		ans = max(ans,can + i + 1);
	}
	for(int i = 0; i < m; i++){
		ll rem = k - b[i];
		if(rem < 0) break;
		int can = upper_bound(a.begin(),a.end(),rem) - a.begin();
		ans = max(ans,can + i + 1);
	}
	
	
	
	cout << ans << "\n";
	return 0;
}
