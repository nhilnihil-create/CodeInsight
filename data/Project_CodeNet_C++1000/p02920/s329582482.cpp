#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
multiset<int>st;
signed main() {
	cin>>N;
	rep(i,1<<N){
		int a;cin>>a;st.insert(a);
	}
	vector<int>used={*--st.end()};st.erase(--st.end());
	rep(i,N){
		vector<int>v;
		for(int j:used){
			if(st.lower_bound(j)==st.begin()){
				cout<<"No"<<endl;return 0;
			}
			v.push_back(*--st.lower_bound(j));
			st.erase(--st.lower_bound(j));
		}
		for(int j:v)used.push_back(j);
	}
	cout<<"Yes"<<endl;
}

