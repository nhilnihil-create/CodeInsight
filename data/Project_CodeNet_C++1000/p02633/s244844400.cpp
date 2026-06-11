#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 1000005
typedef long long int ll;
// int n,m;
// vector<int> adj[mx];

//---dfs--
// bool visited[mx];
// vector<int> val(n,0);

// void dfs(int s, int & cnt_vert, int & cnt_edge){
// 	assert(!visited[s]);
// 	visited[s]=true;
// 	++cnt_vert;
// 	cnt_edge+=adj[s].size();
// 	for(int b:adj[s]){
// 		if(!visited[b]){
// 			dfs(b,cnt_vert,cnt_edge);
// 		}
// 	}
// }
//---dfs---

//---primes---
// vector<bool> prime(N,true);
// int spf[N];

// void calc(){
// 	for(int i=2;i<1e4;i++){
// 		if(!prime[i]) continue;
// 		spf[i]=i;
// 		for(int j=i*i;j<N;j+=i){
// 			prime[j]=false;
// 			spf[j]=i;
// 		}
// 	}
// 	for(int i=2;i<N;i++){
// 		if(!spf[i]) spf[i]=i;
// 	}
// }

// vector<pair<int,int>> getp(int x){
// 	int curr=x;
// 	vector<pair<int,int>> ans;
// 	while(curr>1){
// 		int a=spf[curr];
// 		int count=0;
// 		while(curr%a==0){ curr/=a; count++;}
// 		ans.push_back(make_pair(a,count));
// 	}
// 	return ans;
// }

// bool ispr(int n) {
//     for (int i=2;i*i<=n;++i){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }
//---primes---

//---segment_tree---
// int upd(int t,int val,int l,int r,int y, int z){
// 	if(y<l||y>r) return tr[val];
// 	if(l==r) return tr[val]=z;
// 	int s=(l+r)/2;
// 	upd(t^1,2*val+1,l,s,y,z);
// 	upd(t^1,2*val+2,s+1,r,y,z);
// 	if(t) tr[val]=tr[2*val+1]|tr[2*val+2];
// 	else tr[val]=tr[2*val+1]^tr[2*val+2];
// 	return tr[val];
// }
//int query(){}
//---segment_tree---

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int t=1;
	//cin>>t;
	while(t--){
		int x;
		cin>>x;
		int k=1;
		for(k;k<=360;k++){
			if((k*x)%360==0) break; 
		}
		cout<<k<<"\n";
	}
}
