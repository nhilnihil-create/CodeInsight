#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
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

int N;
map<int,int>mp;
signed main(){
	cin>>N;
	rep(i,N){
		int a;cin>>a;mp[a]++;
	}
	if(mp.size()==1){
		if(mp[0]==N)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		return 0;
	}
	if(N%3||mp.size()>3){
		cout<<"No"<<endl;return 0;
	}
	if(mp.size()==2){
		if(mp[0]==N/3)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}else if(mp.size()==3){
		int res=0;
		for(auto p:mp){
			if(p.second!=N/3){
				cout<<"No"<<endl;return 0;
			}
			res^=p.first;
		}
		if(!res)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
