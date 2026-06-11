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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
  
const int maxl = 1e3 + 10; 
  
void solve() {
	int n;
	cin >> n;
	
	vi l(n);
	for(int i = 0; i < n; i++) cin >> l[i];
	
	sort(all(l));
	
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ans += int(upper_bound(all(l), l[i] + l[j] - 1) - l.begin()) - j - 1;
		}
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