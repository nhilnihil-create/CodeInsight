#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;

int main(void) {
	while(1){
		int n, m;
		vector<int> hana;
		vector<int> taro;
		int taros = 0;
		int hanas = 0;
		int as = 1000000000;
		int at = -1;
		int ah = -1;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		for(int i=0; i<n; i++){
			int t;
			cin >> t;
			taro.pb(t);
			taros += t;
		}
		for(int i=0; i<m; i++){
			int t;
			cin >> t;
			hana.pb(t);
			hanas += t;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(taros - taro[i] + hana[j] == hanas - hana[j] + taro[i])	{
					if(as > hana[j] + taro[i]){
						ah = j;
						at = i;
						as = hana[j] + taro[i];
					}
				}
			}
		}

		if(ah == -1) cout << "-1" << endl;
		else printf("%d %d\n", taro[at], hana[ah]);
	}
	
	return 0;
}