#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

const int INF=1001001001001001001;

int N,K;
int H[333];

int dp[333][333];

signed main(){
	cin>>N>>K;
	rep(i,N)cin>>H[i+1];
	fill_n(*dp,333*333,INF);
	dp[0][0]=0;
	rep(i,N)rep(j,K+1){
		for(int k=i+1;k<=N&&j+(k-i-1)<=K;k++){
			int tmp=max(H[k]-H[i],0ll);
			chmin(dp[k][j+(k-i-1)],dp[i][j]+tmp);
		}
	}

	int ans=INF;
	rep(i,N+1)rep(j,K+1){
		if(j+(N-i)<=K)chmin(ans,dp[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}