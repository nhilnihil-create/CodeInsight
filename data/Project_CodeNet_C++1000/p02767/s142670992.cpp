#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int X[N];
	int MI = 100, MA = 0;
	for(int i=0;i<N;i++){
		cin >> X[i];
		MI = min(X[i], MI);
		MA = max(X[i], MA);
	}
	int ans = 100000000;
	for(int p = MI;p<=MA;p++){
		int tmp = 0;
		for(int i=0;i<N;i++){
			int D = X[i] - p;
			tmp += D * D;
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}
