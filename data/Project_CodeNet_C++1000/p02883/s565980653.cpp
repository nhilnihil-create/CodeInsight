#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	ll k;
	int n;
	cin >> n >> k;
	vector<ll> a(n),f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];
	sort(a.begin(),a.end());
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	ll left = -1, right = (ll)1e13;
	ll mid;
	while(left+1<right){
		mid = (left+right)/2;
		bool ok = [&]{
			ll s = 0;
			rep(i,n) s += max(a[i]-mid/f[i],0ll);
			return s<=k;
		}();
		if(ok){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	cout << right << endl;
	return 0;
}