#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,e[505][505];
void divide(int l,int r,int d){
	if (l==r) return;
	int mid=(l+r)/2;
	divide(l,mid,d+1);
	divide(mid+1,r,d+1);
	For(i,l,mid) For(j,mid+1,r) e[i][j]=d;
}
int main(){
	scanf("%d",&n);
	divide(1,n,1);
	For(i,1,n-1){
		For(j,i+1,n) printf("%d ",e[i][j]);
		puts("");
	}
}