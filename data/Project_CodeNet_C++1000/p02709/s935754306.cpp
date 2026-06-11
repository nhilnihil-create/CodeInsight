#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef array<int,2> pii; 

const int N = 2e3 + 5;
const ll inf = 1e16;

ll dp[N], ndp[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pii> v(n);
	rep(i,0,n){
		cin >> a[i];
		v[i] = pii{a[i],i};
	}
	sort(v.rbegin(), v.rend());
	fill(dp,dp+N, -inf);
	dp[0] = 0;
	rep(i,0,n){
		fill(ndp,ndp+N, -inf);
		int cur = v[i][1];
		rep(lft,0,n+1){
			int ltar = lft;	
			ll lgain = 1LL * a[cur] * abs(ltar-cur);
			gmax(ndp[lft+1], dp[lft] + lgain);
			int rtar = n-1-(i-lft);	
			ll rgain = 1LL * a[cur] * abs(rtar-cur);
			gmax(ndp[lft], dp[lft] + rgain);
		}
		swap(dp,ndp);
	}
	ll ans = *max_element(dp,dp+n+2);
	cout << ans << '\n';
}
