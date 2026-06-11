#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef double db;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) (int)(x.size())
#define sci(x) scanf("%d",&(x))
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define syn ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
ll modpow(ll x,ll n,ll mod){ll res=1;for(;n;n>>=1,x=x*x%mod)if(n&1)res=res*x%mod;return res;}
const db eps=1e-8,PI=acos(-1.0);
const int N=2e5+10,M=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;//998244353
int n,k,c,len;
int dp[N],pos;
char s[N];
int main(){
	sci(n),sci(k),sci(c);
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='o'){
			if(!pos || i-pos>c){
				pos=i;
				len++;
				dp[i]++;
			}
		}
	}
	if(len>k)return 0*puts("");
	pos=n+1;
	len=0;
	per(i,n,1){
		if(s[i]=='o'){
			if(pos==n+1 || pos-i>c){
				pos=i;
				len++;
				dp[i]++;
			}
		}
	}
	if(len>k)return 0*puts("");
	rep(i,1,n){
		if(dp[i]==2){
			printf("%d\n",i);
		}
	}
    return 0;
}