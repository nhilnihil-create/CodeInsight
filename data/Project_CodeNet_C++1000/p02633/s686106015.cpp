#include <bits/stdc++.h>
using namespace std;

int x;

int main(){	
	scanf("%d", &x);
	
	int y = 0;
	for(int i = 1; ; i++){
		y = (y + x) % 360;
		if(y == 0){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
