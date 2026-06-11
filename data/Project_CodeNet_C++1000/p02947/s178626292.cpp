#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	ll n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s.at(i);

	rep(i, n) sort(s.at(i).begin(), s.at(i).end());
	sort(s.begin(), s.end());

	ll cnt = 1;
	ll ans = 0;
	rep(i, n-1){
		if(s.at(i) == s.at(i+1)){
			cnt++;
		}else{
			ans += (cnt*(cnt-1))/2;
			cnt = 1;
		}
	}
	ans += (cnt*(cnt-1))/2;
	cout << ans << endl;
	return 0;
}
