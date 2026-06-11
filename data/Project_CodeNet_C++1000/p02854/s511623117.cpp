#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,A[200005];
signed main(){
	cin>>N;
	int sum=0;
	rep(i,N){
		cin>>A[i];
		sum+=A[i];
	}
	int ans=inf;
	int suml=0;
	rep(i,N){
		suml+=A[i];
		int sumr=sum-suml;
		ans=min(ans,max(suml,sumr)-min(suml,sumr));
	}
	cout<<ans<<endl;
}
