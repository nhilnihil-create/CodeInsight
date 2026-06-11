#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int h, w, n;

int main(){
	scanf("%d %d %d", &h, &w, &n);
	int ans = 999;
	for(int i = 0; i <= h; i++){
		for(int j = 0; j <= w; j++){
			if(i * j + n <= h * w){
				ans = min(ans, (h - i) + (w - j));
			}
		}
	}
	printf("%d\n", ans);
}