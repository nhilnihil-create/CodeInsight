#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>

#define INF 1010000000
#define rep(i,n) for(int i=0;i<int(n);i++)
#define sint(i) scanf("%d",&i)
#define sintt(i,j) scanf("%d%d",&i,&j)
#define sinttt(i,j,k) scanf("%d%d%d",&i,&j,&k)

using namespace std;

int main(){
	while(1){
		int xx,yy;
		sintt(xx,yy);
		if(xx==0)break;
		int n;
		sint(n);
		int masu[18][18];
		int ura[18][18];
		rep(i,18)rep(j,18)ura[i][j]=masu[i][j]=0;
		
		
		rep(k,n){
			int a,b;
			sintt(a,b);
			ura[a][b]=1;
		}
		
		masu[1][1]=1;
		rep(i,xx+1)rep(j,yy+1){
			if(ura[i+1][j+1]==1)continue;
			masu[i+1][j+1]+=masu[i][j+1]+masu[i+1][j];
		}
		
		printf("%d\n",masu[xx][yy]);
	}
}