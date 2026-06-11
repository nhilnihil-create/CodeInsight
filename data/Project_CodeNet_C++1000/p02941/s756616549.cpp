#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
#define BIT(S,i) ((S&(1ll<<i))>0)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

signed main(){
	int N;
	cin>>N;
	vector<int>a(N),b(N);
	REP(i,N)cin>>a[i];
	REP(i,N)cin>>b[i];
	priority_queue<pair<int,int>>que;
	REP(i,N){
		if(a[i]!=b[i])que.push({b[i],i});
	}
	int ans = 0;
	while(que.size()){
		int now = que.top().first;
		int idx = que.top().second;
		que.pop();
		int t = (now - a[idx]) / (b[(idx+1)%N] + b[(idx-1+N)%N]);
		if(t==0){
			cout<<-1<<endl;
			return 0;
		}
		b[idx]-=t*(b[(idx+1)%N] + b[(idx-1+N)%N]);
		now-=t*(b[(idx+1)%N] + b[(idx-1+N)%N]);
		if(b[idx]<a[idx]){
			cout<<-1<<endl;
			return 0;
		}
		if(b[idx]!=a[idx])que.push({now,idx});
		ans+=t;
	}
	cout<<ans<<endl;
}