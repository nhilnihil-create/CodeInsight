#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    vector<int> arr(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> arr[i];
    }

    vector<int> sp(n + 2);

    while(k--) {
    	int cnt = 0;
    	for(i = 1; i <= n; i++) {
    		sp[i] = 0;
    		if(arr[i] == n) {
    			cnt++;
    		}
    	}
    	if(cnt == n) {
    		break;
    	}
    	for(i = 1; i <= n; i++) {
    		int l = max(1, i - arr[i]);
    		int r = min(n + 1, i + arr[i] + 1);
    		sp[l]++;
    		sp[r]--;
    	}
    	for(i = 1; i <= n; i++) {
    		sp[i] += sp[i - 1];
    		arr[i] = sp[i];
    	}
    }

    for(i = 1; i <= n; i++) {
    	cout << arr[i] << " ";
    }
	
    return 0;
}