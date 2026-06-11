#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m, v, p;
	cin >> n >> m >> v >> p;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	int ok = p, ng = n;
	while(ng - ok > 0){
		int mid = (ok + ng + 1) / 2;
		ll cost = 0;
		rep(i,n){
			if(i < p-1 || mid-1 <= i) cost += m;
			else{
				if(a[mid-1] + m < a[i]){
					cost = -1;
					break;
				}
				cost += (a[mid-1] + m) - a[i];
			}
		}
		if(cost < m*v) ng = mid - 1;
		else ok = mid;
	}
	cout << ok << endl;
	return 0;
}
