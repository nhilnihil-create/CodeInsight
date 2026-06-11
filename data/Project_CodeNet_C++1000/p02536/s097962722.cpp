#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 1000000
map<ll,vector<ll> > a;
bool arr[N];
void dfs(ll n){
	arr[n]=true;
	for(auto x:a[n]){
		if (!arr[x]){
			dfs(x);
		}
	}
	}
 
int main(){
	ll n,e,cnt=0;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		ll x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if (!arr[i]){
		dfs(i);
		cnt++;
		}
		}
	cout<<cnt-1;
	return 0;
}