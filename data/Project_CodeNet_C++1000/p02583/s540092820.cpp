#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i){
    	for (int j = i + 1; j < n; ++j){
    		if (a[i] == a[j]) continue;
    		for (int k = j + 1; k < n; ++k){
    			if (a[k] == a[i] || a[k] == a[j]) continue;
    			vector<int> cur(3);
    			cur[0] = a[i], cur[1] = a[j], cur[2] = a[k];
    			sort(cur.begin(), cur.end());
    			if (cur[0] + cur[1] > cur[2]) ans++;
    		}
    	}
    }
    cout << ans << '\n';
    return 0;
}