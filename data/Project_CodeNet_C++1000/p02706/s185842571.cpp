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
	int n, m;
	cin >> n >> m;
	vi a(m);
	ll sum = 0;
	for(int i = 0; i < m; i++) cin >> a[i], sum += a[i];
	
	if(sum > n) cout << -1 << endl; else cout << n - sum << endl;
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