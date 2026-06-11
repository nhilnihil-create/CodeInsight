#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	int e;
	while (scanf("%d", &e), e) {
		int Min = INT_MAX;
		for (int i = 0; i*i*i <= e; i++) {
			for (int j = 0; j*j <= e - i*i*i; j++) {
				Min = min(Min, i + j + e - i*i*i - j*j);
			}
		}
		printf("%d\n", Min);
	}
}