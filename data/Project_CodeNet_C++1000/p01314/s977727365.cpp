#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;

int main(void) {
	vector<int> sum;
	sum.pb(0);
	for(int i=1; i<=1000; i++){
		sum.pb(sum[i-1] + i);
	}

	while(1){
		int n;
		cin >> n;
		if(n == 0) break;

		int ans = 0;
		for(int i=0; i<=n; i++){
			for(int j=i+2; j<=n; j++){
				if(sum[j] - sum[i] == n){
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
	
	return 0;
}