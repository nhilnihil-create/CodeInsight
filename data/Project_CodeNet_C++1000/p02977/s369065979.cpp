#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;

int great_power_2(int k){
	int ret = 1;
	while(k % (ret * 2) == 0){
		ret *= 2;
	}
	return ret;
}

void addedge(int a, int b){
	if(a < 0){
		a = n - a;
	}
	if(b < 0){
		b = n - b;
	}
	printf("%d %d\n", a, b);
}


int main(){
	scanf("%d", &n);
	if(great_power_2(n) == n){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	addedge(1, 2);
	addedge(2, 3);
	addedge(3, -1); // prefer +k and -k encoding
	addedge(-1, -2);
	addedge(-2, -3);
	
	int pv_left = 1, pv_right = 1;
	for(int i = 4; i < n; i += 2){
		addedge(i, i + 1);
		addedge(i + 1, pv_left);
		addedge(pv_right, -i);
		addedge(-i, -(i + 1));
		pv_left = i;
		pv_right = -(i + 1);
	}
	
	if(n % 2 == 0){
		// place the final number pair
		int g = great_power_2(n);
		addedge(n, g);
		addedge(-n, n - (g - 1));
	}
	return 0;
}