#include <bits/stdc++.h>
using namespace std;

int n;


int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			int x = i ^ j;
			x = x & -x;
			int y = 0;
			while (x){
				y++; x /= 2;
			} 
			printf("%d ", y);
		}
		printf("\n");
	}
	return 0;
}