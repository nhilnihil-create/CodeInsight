#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,p[1001000],cnt;
int main(){
	cin>>n;
	if(n<3){puts("No");return 0;}
	int k1=-1,k2=-1;
	if((n+1)%4){
		int r=n/4;
		if((r&-r)==r){
			if(n%4==0){puts("No");return 0;}
			puts("Yes");
			printf("1 %d\n",n/4*4+1);
			printf("1 %d\n",n/4*4);
			printf("%d %d\n",n/4*4+1,n/4*4+n);
			printf("%d %d\n",n/4*4,n/4*4+n+1);
			if(n%4==2){
				printf("%d %d\n",n/4*4,n/4*4+2);
				printf("3 %d\n",n/4*4+2+n);
			}
		}
		else puts("Yes"),k1=r&-r,k2=(n/4)^k1;
	}
	else puts("Yes");
	for(int i=0;i+3<=n;i+=4){
		if(k1==i/4||k2==i/4) continue;
		if(i)p[++cnt]=i;p[++cnt]=i+1;p[++cnt]=i+3;p[++cnt]=i+2;
		if(i)p[++cnt]=i+n;p[++cnt]=i+1+n;p[++cnt]=i+3+n;p[++cnt]=i+2+n;
	}
	if(k1>0){
		int w1=cnt+6,w2=cnt+9;
		p[++cnt]=k1*4;p[++cnt]=k1*4+3;p[++cnt]=k1*4+2;p[++cnt]=k1*4+1;
		p[++cnt]=k1*4+n;p[++cnt]=k1*4+3+n;p[++cnt]=k1*4+2+n;p[++cnt]=k1*4+1+n;
		p[++cnt]=k2*4;p[++cnt]=k2*4+1;p[++cnt]=k2*4+2;p[++cnt]=k2*4+3;
		p[++cnt]=k2*4+n;p[++cnt]=k2*4+1+n;p[++cnt]=k2*4+2+n;p[++cnt]=k2*4+3+n;
		printf("%d %d\n",p[w1],n/4*4),printf("%d %d\n",p[w2],n/4*4+n);
		if(n%4>=1) printf("%d %d\n",p[w1+2],n/4*4+1),printf("%d %d\n",p[w2],n/4*4+1+n);
		if(n%4>=2) printf("%d %d\n",p[w1+2],n/4*4+2),printf("%d %d\n",p[w2+2],n/4*4+2+n);
	}
	for(int i=1;i<cnt;i++)
		cout<<p[i]<<' '<<p[i+1]<<'\n';
	return 0;
}
