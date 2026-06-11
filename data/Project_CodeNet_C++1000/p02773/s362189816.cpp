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

void solve() {
	int n;
	cin >> n;
	map<string, int> u;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		u[s]++;
	}
	
	int mx = 0;
	for(auto s : u) {
		mx = max(mx, s.ss);
	}
	
	vector<string> sc;
	for(auto s : u) {
		if(s.ss == mx) {
			sc.pub(s.ff);
		}
	}
	
	sort(all(sc));
	for(int i = 0; i < sc.size(); i++) cout << sc[i] << endl;
	
	return;
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