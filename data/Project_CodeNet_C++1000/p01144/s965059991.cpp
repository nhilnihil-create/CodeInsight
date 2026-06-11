#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> P;
void solve(int n, int m){
	int sum = 0;
	int ans = 0;
	vector<P> v;
	for(int i=0; i<n; ++i){
		int d, p;
		cin >> d >> p;
		v.push_back(P(p, d));
	}
	sort(v.begin(), v.end());
	for(int i=n-1; i>=0; --i){
		int d = v[i].second;
		int p = v[i].first;
		if(m - sum >= d) sum += d;
		else if(m == sum) ans += d * p;
		else{
			ans += (d - m + sum) * p;
			m = sum;
		}
	}
	cout << ans << "\n";
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) return 0;
		solve(n, m);
	}
}
