#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}

signed main(){
	int N;
	cin >> N;
	multiset<int>st;
	REP(i,1ll<<N){
		int t;
		cin >> t;
		st.insert(t);
	}
	vector<int>v;
	v.push_back(*prev(st.end()));
	st.erase(prev(st.end()));
	st.insert(-1e18);
	st.insert(-1e18);
	st.insert(1e18);
	REP(i,N){
		int num = 1ll << i;
		REP(j,num){
			auto itr = st.lower_bound(v[j]);
			--itr;
			if(*itr==-1e18){
				cout<<"No"<<endl;
				return 0;
			}
			v.push_back(*itr);
			st.erase(itr);
		}
		sort(ALL(v));
	}
	cout<<"Yes"<<endl;
}