#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int ax[4]={1,0,-1,0},ay[4]={0,1,0,-1};
char ch[1000];
int i,j,n,m,f[1000][1000],x,y,ans;
bool b[1000][1000];
void search(int x,int y,int z){
	b[x][y]=true;
	int i,j,p,q;
	for(i=0;i<4;i++){
		p=x+ax[i];q=y+ay[i];
		if((p>0)&&(p<=n)&&(q>0)&&(q<=m)&&(!b[p][q])&&(f[p][q]==z)){
			search(p,q,z);
	    }
	}
}
int main(){
	scanf("%d %d",&n,&m);
	getchar();
	    while((m!=0)&&(n!=0)){
	    ans=0;
	    memset(b,0,sizeof(b));
	 	memset(f,0,sizeof(f));
	 	ans=0;
	 	for(i=1;i<=n;i++){
	 		gets(ch);
	 		for(j=0;j<m;j++)
	 		 if(ch[j]=='*') f[i][j+1]=1;
	 		  else if(ch[j]=='#') {
	 		  	   f[i][j+1]=2;
			   } else f[i][j+1]=3;
		}
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++){
	 	if(!b[i][j]){
	 		search(i,j,f[i][j]);
	 		ans++;
		 }
	 }
	 printf("%d\n",ans);
	 scanf("%d %d",&n,&m);
	 getchar();
    }
}