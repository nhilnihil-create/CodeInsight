//by Top1
#include <bits/stdc++.h>
          
#define f first
#define s second
#define int long long
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>
#define pll pair <long, long>
#define mp make_pair
#define pb push_back
#define pf push_front
#define pp pop_back
#define cerr cout
#define rev reverse
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()
#define forn(i, a, b) for (int i = a; i <= b; i++)
#define boost ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define nxtp next_permutation
#define pvtp prev_permutation
#define KZ return 
#define x1 x21212121
#define y1 y21212121
#define sqr(x) x * x 
      
const int inf = (1e18) + 1;
const int mod = 479001599;
const int maxn = 1e5 + 111;
        
using namespace std;          

int n, m, a[maxn], k = 1;

void solve(){
	cin >> n >> m;

    for (int i = 1; i <= n; i++){
    	cin >> a[i];
    	k = k * a[i] / (__gcd(a[i], k));
    }

    int h = k / 2;
    
    for (int i = 1; i <= n; i++){
    	a[i] /= 2;
    	if ((h / a[i]) % 2 == 0){
    		cout << 0;
    		return;
    	}
    }

    cout << m / h - m / k;                                               
}   
      
main(){
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

    boost;
    
    int q = 1;

    //cin >> q;

    while (q--){
        solve();
    }
}