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

int N,M,wa[100005];
bool ac[100005];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>N>>M;
	while(M--){
		int a;string s;
		cin>>a>>s;
		if(s=="WA"&&!ac[a])wa[a]++;
		if(s=="AC")ac[a]=true;
	}
	int accnt=0,wacnt=0;
	REP(i,N+1){
		if(ac[i]){
			accnt++;wacnt+=wa[i];
		}
	}
	cout<<accnt<<" "<<wacnt<<endl;
}
