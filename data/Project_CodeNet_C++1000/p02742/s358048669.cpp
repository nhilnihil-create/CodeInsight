#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long H, W;
	cin >> H >> W;

	if(H == 1 || W == 1){
		printf("1\n");
		return 0;
	}

	long long ans = 0;
	long long b;
	if((H % 2) == 0){
		b = H / 2;
		ans = b*W;
	}
	else{
		b = (H / 2) + 1;
		ans = b * (W/2); 
		ans += (b-1) * (W/2);
		if((W % 2) == 1){
			ans += b;
		}
	}

	printf("%lld\n", ans);
	return 0;
}