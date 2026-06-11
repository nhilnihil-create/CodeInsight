#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	rep(i,n){
		rep(j,10){
			sort(s[i].begin(),s[i].end());
		}
	}
	map<string,ll> cnt;
	rep(i,n){
		cnt[s[i]]++;
	}
	ll count  = 0;
	for(auto x : cnt){
		auto k = x.first;
		auto v = x.second;
		if(v == 1) continue;
		count += (ll)v*(ll)(v-1)/2;
	}
	cout << count << endl;
}

// cout << fixed << setprecision(15) <<  << endl;