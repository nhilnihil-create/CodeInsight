#include<bits/stdc++.h>
int h,m,t1,t2,K;
int main(){
	scanf("%d%d",&h,&m);
	t1=h*60+m;
	scanf("%d%d",&h,&m);
	t2=h*60+m;
	scanf("%d",&K);K=t2-t1-K;
	printf("%d\n",K);
}