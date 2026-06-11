#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn=1e6+10;
#define p 1000000007
int main(){
	fast;
	ll n,t,cnt=0; cin>>n;
	vector<ll> a(n);
	for(auto &it:a)cin>>it;
	sort(a.begin(), a.end());
	for(auto i=0;i<n;++i){
		for(auto j=0;j<i;++j){
			for(auto k=0;k<j;++k){
				if(a[j]+a[k]>a[i] && a[i]!=a[j] && a[j]!=a[k]){
					++cnt;
				}
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
//prime func
//subset production
//factorization
//modpow
//modinv ( a^(p-2)=a^(-1) (mod p) )
//sieve
//ncr
//euler totien func (co prime divisiors upto n)
//matrix exponentation
//dsu
//Trees
//Graphs(dfs,bfs,shortes path etc.)
//DP-Recursion