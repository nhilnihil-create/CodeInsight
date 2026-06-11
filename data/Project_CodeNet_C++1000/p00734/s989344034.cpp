#include <cstdio>

int main(){
	int n, m;
	int t[100],h[100];
	while(scanf("%d%d", &n, &m)){
		int rt = 1000, rh = 1000;
		int T = 0, H = 0;
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; i++){
			scanf("%d", &t[i]);
			T += t[i];
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &h[i]);
			H += h[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(T-t[i]+h[j] == H-h[j]+t[i] && rt+rh > t[i]+h[j]){
					rt = t[i];
					rh = h[j];
				}
			}
		}
		if(rt == 1000) printf("-1\n");
		else printf("%d %d\n", rt, rh);
	}
}