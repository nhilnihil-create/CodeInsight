#include <bits/stdc++.h>
using namespace std;

signed main(){
	int X, N, i;
	scanf("%d%d", &X, &N);
	vector<int> p(N);
	for(i = 0; i < N; i++){
		scanf("%d", &p[i]);
	}
	int ans = 0;
	for(int q = 0; q <= 101; q++){
		int f = 1;
		for(i = 0; i < N; i++){
			if(q == p[i]){
				f = 0;
			}
		}
		if(f == 0){
			continue;
		}
		if(abs(ans - X) > abs(q - X)){
			ans = q;
		}
	}
	printf("%d\n", ans);
	return 0;
}