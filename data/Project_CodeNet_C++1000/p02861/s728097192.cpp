#include <stdio.h>
#include <math.h>
int n;
int x[10],y[10];
int visit[10];
int cnt;
double dis;
double dist(int a,int b){
	return sqrt((double)((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])));
}
double f(int x,int y){
	printf("%d %d\n",x,y);
	double res = 0;
	if(y==n){
		cnt++;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i] = 1;
			res+= dist(x,i)+f(i,y+1);
			visit[i] = 0;
		}
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis+=dist(i,j)*2;
		}
	}
	printf("%lf\n",dis/(double)n);
}