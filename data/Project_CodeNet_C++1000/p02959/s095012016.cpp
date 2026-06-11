#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> city(n+1);
	vector<int> hero(n);
	rep(i, n+1) cin >> city.at(i);
	rep(i, n) cin >> hero.at(i);

	ll ans = 0;
	rep(i, n){
		int left = min(city.at(i), hero.at(i));
		ans += left;
		city.at(i) -= left;
		hero.at(i) -= left;

		int right = min(city.at(i+1), hero.at(i));
		ans += right;
		city.at(i+1) -= right;
		hero.at(i) -= right;
	}

	cout << ans << endl;
	return 0;
	
}