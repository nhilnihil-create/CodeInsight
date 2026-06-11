/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=500;

int n;
int val[N+3][N+3];

void Solve(int l,int r,int dep){
	if(l==r) return;
	int m=(l+r)>>1;
	for(int i=l;i<=m;i++)
		for(int j=m+1;j<=r;j++)
			val[i][j]=val[j][i]=dep;
	Solve(l,m,dep+1);
	Solve(m+1,r,dep+1);
}
int main(){
	scanf("%d",&n);
	Solve(1,n,1);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			printf("%d",val[i][j]);
			if(j==n) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}