#include <cstdio>
#include <cmath>
int pro[1001];

int main(){
	int n, s[1001];
	while(scanf("%d", &n), n){
		double m = 0, t = 0;
		for(int i = 0;i < n;i++){
			scanf("%d", &s[i]);m += s[i];
		}m /= n;
		for(int i = 0;i < n;i++){
			t += pow(s[i] - m, 2);
		}
		printf("%f\n", sqrt(t/n));
	}
	return 0;
}