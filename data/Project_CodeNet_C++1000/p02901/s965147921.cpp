#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ss second
#define ff first
#define N 10003
#define inf 1000000009
#define ll long long
#define pii pair<int,int>
#define sz(a) int(a.size())
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int n,m,a[N],b[N],pos;
int dp[1<<14];
int v[N],x;
vector <int> E[14];

void f(int st){
	pos = log2(st & ~(st-1));
	int now,ans = inf;
	for(auto i : E[pos]){
		now = st - (st & v[i]);
		if(dp[now] == inf) f(now);
		if(dp[now] == -1)  continue;
		ans = min(ans,a[i] + dp[now]);
	}
	if(ans == inf) dp[st] = -1;
	else dp[st] = ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&a[i],&b[i]);
		for(int j = 0;j < b[i];j++){
			scanf("%d",&x),E[x].pb(i);
			v[i] += (1<<x);
		}
	}
	for(int i = 1;i <= (1<<(n+1))-1;i++) dp[i] = inf;
	f((1<<(n+1))-2);
	printf("%d",dp[(1<<(n+1))-2]);
}
