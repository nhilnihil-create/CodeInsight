#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
int R, C, ans;
bitset<10005> B[10];

void dfs(int k){
	int cnt = 0;
	if(k == R){
		for(int j = 0; j < C; j++){
			int t = 0;
			for(int i = 0; i < R; i++){
				t += B[i][j];
			}
			if(t > R-t){
				cnt += t;
			}else{
				cnt += R-t;
			}
		}
		if(cnt > ans) ans = cnt;
		return;
	}
	
	dfs(k+1);
	B[k].flip();
	dfs(k+1);

}

int main(){
	while(scanf("%d%d", &R, &C), R||C){
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				bool t;
				scanf("%d", &t);
				B[i][j] = t;
			}
		}
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	
	return 0;
}