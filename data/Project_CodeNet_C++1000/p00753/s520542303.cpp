#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
	int n;
	bool prime[300000];

	for (int i = 0; i < 300000 + 1; i++){
		prime[i] = true;
	}

	prime[0] = prime[1] = false;
	for (int i = 2; i < 300000 + 1; i++){
		if (prime[i]){
			for (int j = 0; i * (j + 2) < 300000; j++){
				prime[i * (j + 2)] = false;
			}
		}
	}

	while (true){
		scanf("%d", &n);
		if (n == 0){
			break;
		}

		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++){
			if (prime[i]){
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return (0);
}