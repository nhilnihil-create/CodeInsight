#include<bits/stdc++.h>
using namespace std;
int k;
long long mod = 1000000007;
long long fac[100005];
vector<int>tree[100005];
bool visited[100005];
long long multi(long long a,long long b){
	if(b==0) return 1;
	if(b==1) return a;
	long long ret = multi(a,b/2);
	ret*=ret;
	ret%=mod;
	if(b%2) ret*=a;
	return ret%mod;
}
long long P(long long n,long long r){
	long long ret = fac[n];
	long long down = fac[n-r];
	return (ret*multi(down,mod-2))%mod;
}
long long dfs(long long curr,bool p){
	visited[curr] = true;
	long long child = 0;
	for(int i=0; i<tree[curr].size(); i++){
		int nxt = tree[curr][i];
		if(!visited[nxt]) child++;
	}
	if(k-1-p<child){
		return 0;
	}
	long long ret = P(k-1-p,child);
	for(int i=0; i<tree[curr].size(); i++){
		int nxt = tree[curr][i];
		if(!visited[nxt]){
			ret*=dfs(nxt,1);
			ret%=mod;
		}
	}
	return ret;
}
int main(){
	int n;
	cin>>n>>k;
	fac[0] = 1;
	for(int i=1; i<=100000; i++){
		fac[i] = fac[i-1]*i;
		fac[i]%=mod;
	}

	for(int i=1; i<n; i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	long long ans = k;
	ans*=dfs(1,0);
	cout<<ans%mod;
}