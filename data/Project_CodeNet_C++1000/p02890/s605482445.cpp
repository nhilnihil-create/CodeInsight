#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5;
int occ[N + 5];
ll jumlah[N + 5];
ll ssum[N + 5];
ll psum[N + 5];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i <n;i++) {
		int x;
		cin>>x;
		occ[x]++;
	}
	for(int i = 0;i <= n;i++) jumlah[occ[i]]++;
	for(int i = n;i >= 0;i--) ssum[i] = jumlah[i] + ssum[i + 1];
	for(ll i = 0;i <= n;i++) {
		psum[i] = jumlah[i] * i;
		if(i) psum[i] += psum[i - 1];
	}
//	for(int i = 0;i <= n;i++) cout<<i<<" "<<psum[i]<<" "<<ssum[i]<<endl;
	for(int i = 1;i <= n;i++) {
		ll lo = 1;
		ll hi = n / i;
		ll res = 0;
		while(lo <= hi) {
			ll mid = (lo + hi) / 2;
			if(psum[mid - 1] + mid * ssum[mid] >= mid * i) {
				res = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		cout<<res<<'\n';
	}
}