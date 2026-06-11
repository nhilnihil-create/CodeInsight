#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn=1e6+10;
#define p 1000000007
int main(){
	fast;
	string s; cin>>s;
	if(s[0]=='R' && s[1]=='R' && s[2]=='R')cout<<3<<'\n';
	else
		if(s[0]=='R' && s[1]=='R' || s[1]=='R' && s[2]=='R')cout<<2<<'\n';
		else
			if(s[0]=='R' || s[1]=='R' || s[2]=='R')cout<<1<<'\n';
			else
				cout<<0<<'\n';
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