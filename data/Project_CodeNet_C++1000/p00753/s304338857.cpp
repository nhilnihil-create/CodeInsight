#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void){
	int n;
	
	while(scanf("%d", &n) && n ){
		int ans = 0;
		
		for(int i = n+1; i <= 2*n; i++){
			bool flg = true;
			for(int j = 2; j*j <= i; j++){
				if(i%j == 0){
					flg = false;
					break;
				}
			}
			if(flg){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}