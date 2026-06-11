#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
const db PI=acos(-1.0);
const db eps=1e-6;
const ll mod=1e9+7;
const int inf=2147483647;
const int maxn=100005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n;
ll dp[2005][2005];
struct node{
	int id,val;
}a[2005];
bool cmp(node x1,node x2){
	return x1.val<x2.val;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i].val),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) dp[i][i]=1ll*a[1].val*abs(a[1].id-i);
	rep(len,2,n){
		for(int i=1,j=i+len-1;j<=n;i++,j=i+len-1){
			dp[i][j]=max(dp[i+1][j]+1ll*a[len].val*abs(a[len].id-i),dp[i][j-1]+1ll*a[len].val*abs(a[len].id-j));
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}