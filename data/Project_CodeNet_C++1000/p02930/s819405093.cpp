#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
int vis[1100][1100],n;
inline void go(int le,int ri,int wh){
	if(le>=ri)return;
	int i,j,k,mid=(le+ri)>>1;
	for(i=le;i<=mid;i++)
	  for(j=mid+1;j<=ri;j++)
	    vis[i][j]=vis[j][i]=wh;
	go(le,mid,wh+1);
	go(mid+1,ri,wh+1);
}
int main(){
    int i,j,k;
    scanf("%d",&n);
    go(1,n,1);
    for(i=1;i<n;i++){
      for(j=1;j+i<n;j++)
        printf("%d ",vis[i][j+i]);
      printf("%d\n",vis[i][n]);
    }
	return 0;
}
