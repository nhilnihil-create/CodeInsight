#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	for(int i = 1; i <= 3; i++){
		if(i != A && i != B){
			printf("%d\n", i);
		}
	}
	return 0;
}