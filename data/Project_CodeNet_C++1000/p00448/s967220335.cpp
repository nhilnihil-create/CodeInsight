#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	const int MAX_R = 10, MAX_C = 10000;
	int R, C;
	bool field[MAX_R][MAX_C];
	int a, ans, res, c;
	
	while(true){
		ans = 0;
		scanf("%d%d", &R, &C);
		
		if(R == 0 && C == 0) break;
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				scanf("%d", &a);
				field[i][j] = (a == 0)? true : false;
				if(a == 0) ans++;
			}
		}
		
		for(int i = 0; i < 1 << R; i++){
			for(int k = 0; k < R; k++){//?£???????
				if(i >> k & 1){
					for(int p = 0; p < C; p++) field[k][p] = !field[k][p];
				}
			}
			
			res = 0;
			for(int j = 0; j < C; j++){
				c = 0;
				for(int p = 0; p < R; p++){
					if(field[p][j]){
						c++;
					}
				}
				res += max(c, R - c);
			}
			
			ans = max(res, ans);
			
			for(int k = 0; k < R; k++){//?£???????????????????????????????
				if(i >> k & 1){
					for(int p = 0; p < C; p++) field[k][p] = !field[k][p];
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}