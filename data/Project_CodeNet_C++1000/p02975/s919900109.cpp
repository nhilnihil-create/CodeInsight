#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<ll,int> mp;
	rep(i,n){
		ll a;
		cin >> a;
		++mp[a];
	}
	bool yes = false;
	if((mp[0] == n) || (mp[0] == n/3 && mp.size() == 2)){
		yes = true;
	}
	if(mp.size() == 4){
		bool ok = true;
		vector<ll> v(3);
		int idx = 0;
		for(auto p : mp){
			if(p.first == 0) continue;
			if(p.second != n/3) ok = false;
			v[idx++] = p.first;
		}
		if((v[0]^v[1]^v[2]) != 0) ok = false;
		if(ok) yes = true;
	}
	cout << (yes ? "Yes" : "No") << endl;
	return 0;
}