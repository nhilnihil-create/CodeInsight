#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<string, int> > a;
    for(int i = 0; i < n; ++i) {
    	string r1; int r2;
    	cin >> r1 >> r2;
    	a.push_back({r1, r2});
    }
    string use;
    cin >> use;
    int ans = 0, fl = 0;
    for(int i = 0; i < n; ++i) {
    	if(fl == 0 && a[i].first != use) continue;
    	if(fl == 0 && a[i].first == use) {
    		fl = 1;
    		continue;
    	}		
    	ans += a[i].second;
    }
    cout << ans;
    return 0;
}