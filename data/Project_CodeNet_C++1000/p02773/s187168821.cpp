#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	map<string,int> mp;
	rep(i,n){
		string s;
		cin >> s;
		mp[s]++;
	}
	int mx = 0;
	for(auto p: mp){
		mx = max(mx, p.second);
	}
	vector<string> v;
	for(auto p: mp){
		if(p.second == mx) v.push_back(p.first);
	}
	sort(v.begin(),v.end());
	for(auto p: v){
		cout << p << endl;
	}
    return 0;
}

