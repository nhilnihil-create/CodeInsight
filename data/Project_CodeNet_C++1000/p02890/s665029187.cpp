#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int N, A, i, l, h, r;
	scanf("%lld", &N);
	vector<int> Anum(N + 1, 0), num(N + 1, 0);
	for(i = 0; i < N; i++){
		scanf("%lld", &A);
		Anum[A]++;
		num[Anum[A]]++;
	}
	for(i = 1; i <= N; i++) num[i] += num[i - 1];
	for(i = 1; i <= N; i++){
		for(l = 0, h = 0, r = N + 1; r - l > 1; h = (l + r) / 2){
			if(num[h] < h * i) r = h;
			else l = h;
		}
		printf("%lld\n", l);
	}
	return 0;
}