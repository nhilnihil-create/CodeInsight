#include<cstdio>
const int N=505;
int n,go[N][N];
void Solve(int l,int r,int id) {
	if(l==r) return ;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
			go[i][j]=id;
	Solve(l,mid,id+1);
	Solve(mid+1,r,id+1);
}
void Print() {
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<n;j++)
			printf("%d ",go[i][j]);
		printf("%d\n",go[i][n]);
	}
}
int main() {
	scanf("%d",&n);
	Solve(1,n,1);
	Print();
	return 0;
}