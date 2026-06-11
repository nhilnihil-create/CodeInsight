#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 5000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	map<char,int> m;
	cin >> s;

	rep(i,s.size()){
		m[s[i]]++;
	}

	if(m.size() != 2){
		cout << "No" << endl;
	}
	else{
		for(auto p : m){
			if(p.second != 2){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}
