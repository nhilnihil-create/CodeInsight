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

int nomal(){
	int ans=0;
	ans=5*20+5*19;
	return ans;
}
int mod3(){
	int ans=0;
	ans=20*10;
	return ans;
}

int so_nissu(){
	int ans=0;
	ans+=333*mod3()+666*nomal();
	return ans;
}

int main(){
	int n,y,m,d;
	int ans=so_nissu();
	cin>>n;
	rep(i,0,n){
		int cnt=0;
		cin>>y>>m>>d;
		if(y%3==0){
			cnt=(y/3-1)*mod3()+y*2/3*nomal();
			cnt=cnt+(m-1)*20+d-1;
		}else{
			cnt=y/3*mod3()+(y/3*2+y%3-1)*nomal();
			if(m%2==1){
				cnt=cnt+m/2*39+d-1;
			}else{
				cnt=cnt+m/2*19+(m/2-1)*20+d;
			}
		}
		print(ans-cnt);
	}
	return 0;
}
