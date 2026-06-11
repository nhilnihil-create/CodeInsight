#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define all(x) x.begin(), x.end()

signed main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int cou = 1;
		bool t = true;
                int x = i;
		while(t){
			if(x/10 >= 1){
				cou++;
				x /= 10;
			}
			else t = false;
		}
		if(cou%2 == 1) ans++;
	}
	
	cout << ans << endl;
	
	return 0;			
}