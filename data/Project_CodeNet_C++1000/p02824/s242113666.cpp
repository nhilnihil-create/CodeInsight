#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, v, p;
	cin >> n >> m >> v >> p;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	int low = p, high = n;
	while(low < high){
		int mid = (low + high + 1) >> 1;
		ll total = 0;
		rep(i, n){
			if(i < p-1 || i >= mid-1) total += m;
			else{
				if(a[i] > a[mid-1]+m){
					total = -1;
					break;
				}
				total += (a[mid-1] + m) - a[i];
			}
		}
		if(total >= (ll) m * v) low = mid;
		else high = mid - 1;
	}
	cout << low << endl;
	return 0;
}