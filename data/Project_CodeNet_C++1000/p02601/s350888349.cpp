#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
inline ll r() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define d r()
ll a,b,c,k;
string ans="No";
void dfs(ll x,ll y,ll z,ll u){
	if(u==k+1){
		if(z>y&&y>x)ans="Yes";
		return;
	}
	dfs(x*2,y,z,u+1);
	dfs(x,y*2,z,u+1);
	dfs(x,y,z*2,u+1);
}
int main(){
	a=d,b=d,c=d;
	k=d;
	dfs(a,b,c,1);
	cout<<ans;	
	return 0;
}