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
	
	int ok = 1;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(a % 2 == 0) {
			if(a%3 && a%5) {
				ok = 0;
			}
			
			if(!ok) {
				cout << "DENIED" << endl;
				return;
			}
		}
	}
	
			cout << "APPROVED" << endl;
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