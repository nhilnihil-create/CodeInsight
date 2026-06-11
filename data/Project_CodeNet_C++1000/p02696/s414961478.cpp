#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define for0(i,a,b) for (int i=a;(i<b);i++)
#define for1(i,a,b) for (int i=a;(i<=b);i++)
#define dec0(i,a,b) for (int i=a;(i>b);i--)
#define dec1(i,a,b) for (int i=a;(i>=b);i--)
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const int INF=0x3f3f3f3f;
const int N=1e6+7;
const int mod=1e9+7;
int maxn,minn;
int T,n,m,q;

int main(){
	ll a,b,n;
	cin>>a>>b>>n;
	ll ans=(a*min(n,(b-1)))/b; 
	ans=max(ans,((a*n)/b)-(a*(n/b)));
	printf("%lld\n",ans);

	return 0;
}

