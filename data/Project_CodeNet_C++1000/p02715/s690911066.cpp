#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

ll power(ll a, ll b) {
	ll result = 1;
	while(b) {
		if(b % 2) result = (result * a) % P;
		a = (a * a) % P;
		b /= 2;
	}
	
	return result;
}

void solve() {
	int n, k;
	cin >> n >> k;
	
	ll ans = k;
	vector<ll> cnt(k + 1, 0);
	cnt[k] = 1;
	for(int i = k - 1; i >= 1; i--) {
		int nd = k / i;
		cnt[i] = power(nd, n);
		for(int j = i + i; j <= k; j += i) {
			cnt[i] = (cnt[i] - cnt[j] + P) % P;
		}
		
		ans = (ans + (cnt[i] * i) % P) % P;
	} 
	
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