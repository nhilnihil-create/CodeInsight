#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514],cnt[214514];
bool f[214514];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=-1;
	}
	f[1]=1;
	cnt[1]=0;
	ll now=1,num=1;
	while(1){
		if(f[a[now]])break;
		now=a[now];
		f[now]=1;
		cnt[now]=num;
		num++;
	}
	if(k>=num){
		ll roop=num-cnt[a[now]];
		k-=cnt[a[now]];
		k%=roop;
		k+=cnt[a[now]];
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==k){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
