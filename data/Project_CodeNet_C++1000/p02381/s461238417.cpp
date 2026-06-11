#include<cstdio>
#include<cmath>

int main(){
	int n;
	double score[1000];
	double a, sum, ave;
	scanf("%d", &n);
	while(n){
		sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%lf", &score[i]);
			sum += score[i];
		}
		ave = sum / n;
		a = 0;
		for(int i = 0; i < n; i++){
			a += (score[i] - ave) * (score[i] - ave);
		}
		a /= n;
		printf("%lf\n", sqrt(a));
		scanf("%d", &n);
	}
	return 0;
}