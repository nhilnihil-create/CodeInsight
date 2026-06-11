#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];

	sort(a.begin(),a.end());
	sort(f.rbegin(),f.rend());

	ll ng = -1, ok = 1e13;
	while(ok - ng > 1){
		ll mid = ok + ng; mid /= 2;
		ll count = 0;
		rep(i,n){
			// midを下回るまで修行する
			ll ob = mid / f[i];
			count += max(0ll, a[i] - ob);
		}
		if(count <= k) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
