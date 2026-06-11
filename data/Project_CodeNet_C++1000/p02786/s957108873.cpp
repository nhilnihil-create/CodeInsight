#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define P 1000000007
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

map<ll, ll> dp;

ll g(ll h) {
	if(h == 1) return 1ll;
	
	if(!dp.count(h)) dp[h] = g(h / 2) * 2 + 1;
	
	return dp[h];
}

void solve() {
	ll h;
	cin >> h;
	
	cout << g(h) << endl;
}

int main(){
#define MULTITEST 0
#if MULTITEST   
 
    CASET {
        solve();
    }
    
#else

    solve();
    
#endif

    return 0;
}