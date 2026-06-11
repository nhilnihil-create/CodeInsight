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
	int h, a;
	cin >> h >> a;
	
	int num = 0;
	while(h > 0) {
		h -= a;
		num++;	
	}
	
	cout << num << endl;
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