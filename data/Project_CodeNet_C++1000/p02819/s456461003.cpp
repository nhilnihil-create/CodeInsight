#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int n, ehPrimo[N];
vector<int> primos;

void sieve(){
	for (int i = 0; i < N; i++)
		ehPrimo[i] = true;

	ehPrimo[1] = false;
	ehPrimo[2] = true;

	for (int i = 2; i < N; i++){
		if (ehPrimo[i]){
			primos.push_back(i);
			for (int j = i+i; j < N; j += i){
				ehPrimo[j] = false;
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	sieve();

	scanf("%d", &n);

	int op1 = upper_bound(primos.begin(), primos.end(), n) - primos.begin(),
		op2 = lower_bound(primos.begin(), primos.end(), n) - primos.begin();

	if (primos[op2] == n){
		printf("%d\n", primos[op2]);
	} else {
		printf("%d\n", primos[op1]);
	}

	return 0;
}