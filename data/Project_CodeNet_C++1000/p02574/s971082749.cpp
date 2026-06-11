#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
int n, cnt[N], freq[N], x[N], vi[N];

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &x[i]);
		freq[x[i]]++;
	}

	for (int i = 0; i < n; i++){
		if (vi[x[i]]) continue;
		vi[x[i]] = true;
		for (int j = 1; j*j <= x[i]; j++){
			if (x[i]%j == 0){
				if (x[i]/j == j){
					cnt[j] += freq[x[i]];
				} else{
					cnt[x[i]/j] += freq[x[i]];
					cnt[j] += freq[x[i]];
				}
			}
		}
	}

	bool coprime = true, pairwise = true;

	for (int i = 2; i <= 1000000; i++){
		if (cnt[i] == n){
			coprime = false;
			break;
		}
		if (cnt[i] > 1){
			pairwise = false;
			//break;
		}
	}

	if (!coprime){
		printf("not coprime\n");
	} else {
		if (pairwise) printf("pairwise ");
		else	printf("setwise ");
		printf("coprime\n");
	}

	return 0;
}