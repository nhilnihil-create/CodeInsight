#include<bits/stdc++.h>
#include<cxxabi.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second
#define All(x) (x).begin(),(x).end()
#define TYPEVS(x) typeid(x).name()
#define TYPEGC(x) abi::__cxa_demangle(typeid(x).name(), 0, 0, 0)
#define Y1 "YES"
#define N1 "NO"
#define ENDL '\n'
#define count2(x) _builtin_popcount(x)
ll nums[6001];
ll sat[4001][3001],ans;
ll mod=998244353;
int main(){
	ll n,s;
	cin>>n>>s;
	sat[0][0]=1;//sat[i][j]表示选择其中不超过i个数，和为j的方案 
	for(ll i=0;i<n;++i)
	cin>>nums[i];
	for(ll i=0;i<n;++i){
		for(int j=0;j<=s;j++){
			sat[i+1][j]+=2*sat[i][j];
			sat[i+1][j]%=mod;
			if(j+nums[i]<=s)
			sat[i+1][j+nums[i]]+=sat[i][j];
			sat[i+1][j+nums[i]]%=mod;
		}
	}
	cout<<sat[n][s];
}
