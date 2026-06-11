#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

const int INF=1001001001001001001ll;

int N;
int A[2222];

int dp[2222][2222];

signed main(){
	cin>>N;
	rep(i,N)cin>>A[i];

	vpint ord;
	rep(i,N)ord.eb(A[i],i);
	sort(all(ord));reverse(all(ord));

	fill_n(*dp,2222*2222,-INF);
	dp[0][0]=0;
	rep(i,N){
		rep(j,N){
			int k=ord[i].se;
			chmax(dp[i+1][j+1],dp[i][j]+A[k]*abs(j-k));
			chmax(dp[i+1][j],dp[i][j]+A[k]*abs(N-(i-j)-1-k));
		}
	}

	int ans=-INF;
	rep(i,N+1)chmax(ans,dp[N][i]);
	cout<<ans<<endl;
    return 0;
}

