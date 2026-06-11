#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n;
ll S,a[200005],b[60];
void insert(ll x){
	Rep(i,59,0)
		if (x&(1ll<<i)){
			if (!b[i]){
				b[i]=x; break;
			}
			else
				x^=b[i];
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]),S^=a[i];
	For(i,1,n) insert(a[i]-(a[i]&S));
	ll ans=0;
	Rep(i,59,0)
		if ((ans^b[i])>ans)
			ans^=b[i];
	printf("%lld\n",2*ans+S);
}