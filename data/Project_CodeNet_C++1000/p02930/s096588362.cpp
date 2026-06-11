#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=505;
int n;
int a[maxn][maxn];

void solve(int l,int r,int d){
	if(l==r)return;
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++)for(int j=mid+1;j<=r;j++)a[i][j]=d;
	solve(l,mid,d+1);
	solve(mid+1,r,d+1);
} 

int main(){
	scanf("%d",&n);
	solve(1,n,1);
	REP(i,n-1)for(int j=i+1;j<=n;j++)printf("%d%c",a[i][j],j==n?'\n':' ');
	return 0;
}