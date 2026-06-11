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
const int mo=1000000007;
const int N=200005;
char s[N];
int a[N],tp[N],n;
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,2*n) a[i]=(s[i]=='B');
	Rep(i,2*n+1,1) a[i]^=a[i-1];
	For(i,1,2*n){
		if (a[i]) tp[i]=0,a[i]^=1;
		else tp[i]=1,a[i+1]^=1;
		//printf("%d ",tp[i]);
	}
	int S=0,ans=1;
	For(i,1,2*n)
		if (tp[i]==0) ++S;
		else ans=1ll*ans*(S--)%mo;
	if (S) ans=0;
	For(i,1,n) ans=1ll*ans*i%mo;
	printf("%d\n",ans);
}