#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> o;
map<int, int> ad;
vector<ll> c;

int main(){
	string s, t;
	cin >> s >> t;
	vector<vector<ll>> a(26, vector<ll>(0));
	rep(i, s.size()){
		a.at(s.at(i) - 'a').push_back(i);
	}
	rep(i, 26) a.at(i).push_back(1000000);
	ll k = -1;
	ll km = 0;
	ll ans = 0;
	string test = "";
	test += s.at(0);
	rep(i, t.size()){
		if(a.at(t.at(i) - 'a').at(0) == 1000000){
				cout << -1 << endl;
				return 0;
		}
	}
	rep(i, t.size()){
		km = k;
		k++;
		ll l = lower_bound(a.at(t.at(i) - 'a').begin(), a.at(t.at(i) - 'a').end(), k) - a.at(t.at(i) - 'a').begin();
		if(a.at(t.at(i) - 'a').at(l) != 1000000){
			k = a.at(t.at(i) - 'a').at(l);
			ans += k-km;
//			test += s.substr(km, k);
		}else{
			k = 0;
			ll l = lower_bound(a.at(t.at(i) - 'a').begin(), a.at(t.at(i) - 'a').end(), k) - a.at(t.at(i) - 'a').begin();
			k = a.at(t.at(i) - 'a').at(l);
			ans += s.size() - (km+1);
			ans += k+1;
//			test += s.substr(km);
//			test += s.substr(0, k);
		}
//		cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}