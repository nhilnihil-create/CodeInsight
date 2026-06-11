#include <stdio.h>

int main()
{
	int n;
	int i,j,k,l;
	int ans;
	while(scanf("%d",&n) != EOF){
		ans = 0;
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				for(k = 0; k < 10; k++){
					for(l = 0; l < 10; l++){
						if(i + j + k + l == n)ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}