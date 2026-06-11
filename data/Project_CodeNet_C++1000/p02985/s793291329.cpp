#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool f[114514];
int main(){
	ll n,k;
	cin>>n>>k;
	vector<vector<ll>>v(n+1);
	for(int i=0;i<n-1;i++){
		ll a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<ll>que;
	que.push(1);
	f[1]=1;
	ll ans=k,mod=1e9+7;
	while(!que.empty()){
		ll x=que.front();
		que.pop();
		ll cnt=1;
		for(ll p:v[x]){
			if(f[p])cnt++;
			else{
				f[p]=1;
				que.push(p);
			}
		}
		ll num=v[x].size()+1-cnt;
		while(num){
			ans*=(k-cnt);
			ans%=mod;
			cnt++;
			num--;
		}
	}
	cout<<ans;
	return 0;
}