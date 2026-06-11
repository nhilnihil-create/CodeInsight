#include <bits/stdc++.h> 
using namespace std;
int ans[1000002];
int ask(int x){
	if(x==2||x==3)return 2;
	int y=0;
	int k=(int)sqrt(x);
	for(int i=1;i<=k;i++){
		if(x%i==0)y++;
	}
	y*=2;
	if(k*k==x)y--;
	return y;
}
int tmp;
void process(){
	for(int i=2;i<=1e6;i++){
		ans[i]=tmp+ask(i-1);
		tmp=ans[i];
	}
}
int main(){
	int p,q;
	scanf("%d",&p);
	for(int i=1;i<=1e6;i++) ans[i]=0;
	ans[1]=0;
	tmp=0;
	process();
//	q=ask(p);
//	printf("%d",q);
	printf("%d",ans[p]);
} 