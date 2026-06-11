// cities to vapori-
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){

	fastio;
	int n;
	cin >> n;
	vector<int> w(n);
	REP(i,0,n) cin >> w[i];

	int ans = INT_MAX;
	int l = 0, r = 0;
	REP(i,0,n) r += w[i];

	for(int i = 0; i+1 < n; ++i){
		r -= w[i];
		l += w[i];
		ans = min(ans,abs(l-r));
	}
	cout << ans << endl;


	return 0;
}
