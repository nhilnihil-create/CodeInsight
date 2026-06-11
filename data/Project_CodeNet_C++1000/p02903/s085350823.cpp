#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int h, w, a, b;

int main(){
	scanf("%d %d %d %d", &h, &w, &a, &b);
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			int output = (i <= b) ^ (j <= a);
			printf("%d", output);
		}
		puts("");
	}
	return 0;
}