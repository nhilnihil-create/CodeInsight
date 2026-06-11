#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 500
int n,a[MAXN+1][MAXN+1];
void slove(int l,int r,int id){
	if(l==r)return ;
	int mid=(l+r)>>1;
	slove(l,mid,id+1),slove(mid+1,r,id+1);
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
		a[i][j]=id; 
}
int main()
{
	scanf("%d",&n);
	slove(1,n,1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
} 