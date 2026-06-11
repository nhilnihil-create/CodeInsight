#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s,t;
	cin >> s >> t;
	vector<vector<int>> a(26);
	
	REP(i,s.size()){
		a[s[i]-'a'].push_back(i);
	}
	
	int count=0;
	int now=-1;
	REP(i,t.size()){
		int sz = a[t[i]-'a'].size();
		if(sz == 0){
			cout << -1 << endl;
			return 0;
		}
		
		int ok = sz;
		int ng = -1;
		while(ok-ng > 1){
			int mid = (ok+ng)/2;
			if(now < a[t[i]-'a'][mid]){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		if(ok==sz){
			count++;
			now = a[t[i]-'a'][0];
		}else{
			now = a[t[i]-'a'][ok];
		}
		
	}
	
	
	cout << (ll)count*(ll)s.size() + (ll)(now+1) << endl;
	
	return 0;
}