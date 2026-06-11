#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define eps 0.000000001
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e6+5;
bool vis[maxn];
ll prime[maxn],cnt=0;
unordered_map<int,int> mp;
void getprime(ll maxn){
	for(ll i=2;i<maxn;i++){
		if(!vis[i]) prime[cnt++]=i,mp[i]=1;
		for(ll j=0;j<cnt&&prime[j]*i<maxn;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break; 
		}
	}
}

int n,a[maxn],ct[maxn];
int main(){
	scanf("%d",&n);getprime(maxn);
	rep(i,1,n) scanf("%d",&a[i]);
	int cur=a[1];
	rep(i,1,n){
		cur=__gcd(cur,a[i]);
	}
	if(cur!=1){puts("not coprime");return 0;}	
	rep(i,1,n){
		int x=a[i];
		if(mp[x]==1){
			ct[x]++;
			if(ct[x]>1){
				puts("setwise coprime");
				return 0;
			}			
			continue;
		}
		for(int j=0;j<cnt&&prime[j]<=x;j++){
			int flag=0;
			while(x%prime[j]==0){
				flag=1;
				x/=prime[j];
			}
			if(flag) ct[prime[j]]++;
			if(ct[prime[j]]>1){
				puts("setwise coprime");
				return 0;
			}
		}
	}
	puts("pairwise coprime");
}
