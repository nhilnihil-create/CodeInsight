#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int L[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &L[i]);
	}
	int counter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if(L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i]) {
                    if(L [i] != L[j] && L[i] != L[k] && L[j] != L[k]) {
                        counter++;
					}
				}
			}
		}
	}
	printf("%d", counter);
	
	return 0;
}