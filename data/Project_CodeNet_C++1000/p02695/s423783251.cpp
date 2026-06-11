#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll a[52],b[52],c[52],d[52];	ll n,m,q;
ll ans,ch[12];
void cal(){
	ll cnt=0;
	for(ll i=0;i<q;i++){
		if(ch[b[i]]-ch[a[i]]==c[i]){
			cnt+=d[i];
		}
	}
	ans=max(ans,cnt);
}
void dep(ll now,ll cnt){
	if(now==n){
		cal();
		return ;
	}
	for(ll i=cnt;i<=m;i++){
		ch[now]=i;
		dep(now+1,i);
	}
}
int main() {

	cin>>n>>m>>q;

	for(ll i=0;i<q;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		a[i]--;b[i]--;
	}
	dep(0,1);
	cout <<ans;
	// your code goes here
	return 0;
}