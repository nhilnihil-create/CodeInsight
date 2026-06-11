#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
#define FOR(i,a,b) for (ll i = (ll)(a); i < (b); i++)
#define ROF(i,a,b) for (ll i = (ll)(b)-1; i >= (a); i--)

ll MOD = 1000000007;
ll INF = 1LL << 60;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int h,w,a,b;cin>>h>>w>>a>>b;
	FOR(i,0,b) {
		FOR(j,0,a) {
			cout<<'0';
		}
		FOR(j,a,w) {
			cout<<'1';
		}
		cout<<'\n';
	}
	FOR(i,b,h) {
		FOR(j,0,a) {
			cout<<'1';
		}
		FOR(j,a,w) {
			cout<<'0';
		}
		cout<<'\n';
	}
}