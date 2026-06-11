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


int main(){
	while(1){
		int n,m,s[100],t[100],sans=0,tans=0,ans=-1;
		bool ok=false;
		cin>>n>>m;
		if(n==0)break;
		rep(i,0,n)cin>>s[i],sans+=s[i];
		rep(i,0,m)cin>>t[i],tans+=t[i];
		sort(s,s+n);
		sort(t,t+m);
		int d=sans-tans;
		if(d%2){
			print(ans);
			continue;
		}
		if(d>0){
			rep(i,0,n){
				rep(j,0,m){
					if(s[i]-t[j]==d/2){
						print(s[i]<<" "<<t[j]);
						ok=true;
					}
					if(ok)break;
				}
				if(ok)break;
			}
		}

		if(d==0){
			rep(i,0,n){
				rep(j,0,m){
					if(s[i]==t[j]){
						ok=true;
						print(s[i]<<" "<<t[j]);
						break;
					}
				}
				if(ok)break;
			}
		}

		if(d<0){
			rep(j,0,m){
				rep(i,0,n){
					if(t[j]-s[i]==-d/2){
						print(s[i]<<" "<<t[j]);
						ok=true;
					}
					if(ok)break;
				}
				if(ok)break;
			}
		}
		if(ok)continue;
		print(ans);
	}
	return 0;
}
