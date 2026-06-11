#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define P 1000000007
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

void solve() {
	ll n, k;
	cin >> n >> k;
	
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(all(a));
	reverse(all(a));
	
	ll ans = 0;
	for(int i = k; i < n; i++) ans += a[i];
	cout << ans << endl;
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