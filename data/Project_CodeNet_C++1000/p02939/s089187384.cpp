#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	string s; cin>>s;
	string memo;
	int ans=0;
	while(!s.empty()){
		int m=s.size();
		string t;
		if(m==1){
			if(s!=memo)ans++;
			s.pop_back();
		}
		else{
			t.push_back(s[m-1]);
			s.pop_back();
			if(memo==t){
				t.push_back(m-2);
				s.pop_back();
			}
			ans++;
			memo=t;
		}
	}
	cout<<ans<<endl;
	return 0;
}