#include <cstdio>
#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,n){
		int y,m,d,ans=0;
		scanf("%d%d%d",&y,&m,&d);
		if(m%2==1 || y%3==0) ans+=(21-d);
		else ans+=(20-d);
		m++;
		if(m==11) m=1,y++;
		while(m!=1){
			if(m%2==1 || y%3==0) ans+=20;
			else ans+=19;
			m++;
			if(m==11) m=1,y++;
		}
		while(y!=1000){
			if(y%3==0) ans+=200;
			else ans+=195;
			y++;
		}
		printf("%d\n",ans);
	}
	return 0;
}