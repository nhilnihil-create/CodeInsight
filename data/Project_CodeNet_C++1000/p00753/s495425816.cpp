#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define alint(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int prime[300010];
bool is_prime[300010];

void sieve(int n){
	int p=0;
	for(int i=0;i<=n;i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
		}
	}
}

int main(){
	sieve(300000);
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		int ans=0;
		rep(i,n+1,2*n+1){
			if(is_prime[i]) ans++;
		}
		o(ans);
	}
}