#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100010;
const int MOD=1000000007;
const int inf=1000000007;
const long long INF=1000000000000000007;
using ll=long long;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};


vector<int> v;
void generate_sosu(){
	v.push_back(2);
	rep(i,2,250000){
		rep(j,0,v.size()){
			if(i%v[j]==0)break;
			if(j==v.size()-1)v.push_back(i);
		}
	}
	return;
}


int main(){
	generate_sosu();
	while(1){
		int n;
		int ans,s=0,e=0;
		cin>>n;
		if(n==0)break;
		rep(i,0,v.size()){
			if(v[i]<=n)s=i+1;
			if(v[i]>2*n){
				e=i;
				break;
			}
		}
		ans=e-s;
		print(ans);
	}
	return 0;
}
