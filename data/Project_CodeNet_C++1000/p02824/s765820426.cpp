#include <bits/stdc++.h>
////////////////////////////////////////////////////////////
#define all(x) (x).begin(), (x).end() 
const int inf = 1e9;
const long long INF=1e15;
#define endl '\n'
#define rep(i, n) for(int i=0;i<(n);++i)
#define repp(i, a, b) for(int i=(a);i<=(b);++i)
#define pb push_back
#define eb emplace_back
#define fastio ios::sync_with_stdio(false);cin.tie(0); //cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

int solve() {
	ll n,m,v,p;
	cin >>n>>m>>v>>p;
	vll a(n); rep(i,n)cin>>a[i];
	sort(all(a), greater<ll>());
	auto chk = [&](int x) {
		if(x < p) return true;
		if(a[x]+m < a[p-1]) return false;
		// p-1+n-x
		ll bsum = 0;
		for(int i=p-1;i<x;i++) bsum += max(0ll, a[x]+m-a[i]);
		if(bsum + (p-1+n-x)*m >= m*v) return true;
		return false;
	};
	int l =0, r=n;
	while(l!=r) {
		int mid=(l+r)/2;
		if(chk(mid) == false) r=mid;
		else l = mid+1;
	}
	cout << l;
}

int main() {
	fastio;
	solve();
}

