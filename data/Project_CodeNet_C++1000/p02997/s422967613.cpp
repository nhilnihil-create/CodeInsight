#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back
#define fi first
#define se second

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
void cmps(vector<int>&v,int &i){
	i=lower_bound(all(v),i)-v.begin();
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,K;
signed main(){
	cin>>N>>K;
	if((N-1)*(N-2)/2<K){
		cout<<-1<<endl;return 0;
	}
	vector<P>v;
	for(int i=2;i<=N;i++)v.pb({1,i});
	int now=(N-1)*(N-2)/2;
	for(int i=2;i<N;i++){
		for(int j=i+1;j<=N;j++){
			if(now>K){
				v.pb({i,j});now--;
			}else goto ok;
		}
	}
	ok:;
	cout<<v.size()<<endl;
	for(auto p:v)cout<<p.first<<" "<<p.second<<endl;
}

