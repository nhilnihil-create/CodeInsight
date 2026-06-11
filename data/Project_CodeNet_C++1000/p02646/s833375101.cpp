#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	lli a,b,v,w,t;
	cin >> a >> v >> b >> w >> t;
	if( a== b){
		cout << "YES" <<newl;
		return;
	}
	if(w >= v){
		cout << "NO" << newl;
		return;
	}
	lli c = abs(a - b);
	lli x = abs(v - w);
	if(c <= x * t) cout << "YES" << newl;
	else cout << "NO" << newl;

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
