#include <iostream>
#include <numeric>
using namespace std;

int INF = 1<<25;

int main() {
	int n, m;
	while(cin >> n >> m && (n || m)){
		int taro[100], hana[100];
		for(int i = 0; i < n; ++i)
			cin >> taro[i];
		for(int i = 0; i < m; ++i)
			cin >> hana[i];
			
		int tsum = accumulate(taro, taro + n, 0), hsum = accumulate(hana, hana + m, 0), res = INF;
		int anst = 0, ansh = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int t = tsum - taro[i] + hana[j];
				int h = hsum + taro[i] - hana[j];
				if(t == h){
					int change = taro[i] + hana[j];
					if(res > change){
						res = change;
						anst = taro[i];
						ansh = hana[j];
					}
				}
			}
		}
		if(res == INF)
			cout << -1 << endl;
		else
			cout << anst << " " << ansh << endl;
	}
	return 0;
}