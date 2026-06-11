#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

template<class Type_a,class Type_b> bool chmax(Type_a &a,const Type_b &b){if(a<b){a=b;return true;}return false;}
template<class Type_a,class Type_b> bool chmin(Type_a &a,const Type_b &b){if(a>b){a=b;return true;}return false;}

int main(){
	int n,m;
	cin>>n>>m;
	
	vi a(m),s(m,0);
	REP(i,m){
		int b;
		cin>>a[i]>>b;
		REP(j,b){
			int c;
			cin>>c;
			s[i]|=1<<(c-1);
		}
	}
	
	vi dp(1<<n,INF);
	dp[0]=0;
	REP(i,m)REP(j,1<<n){
		chmin(dp[j|s[i]],dp[j]+a[i]);
	}
	
	if(dp[(1<<n)-1]==INF) cout<<-1<<endl;
	else cout<<dp[(1<<n)-1]<<endl;
}