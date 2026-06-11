#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int ans;

void solve(void){
	int n;
	cin >> n;
	for(int a = 1; a <= n-1; a++){
		int last = n / a;
		if(n % a == 0){
			last--;
		}
		if(!last){
			continue;
		}
		ans += (last-1+1);
	}
	
	cout << ans << endl;
}

signed main() {
int t = 1;
// cin >> t;    
	while(t--)
    solve();

    return 0;
}
