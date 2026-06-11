#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll mycalc(ll S) {
	ll count = 0;
	vector<ll> vec(S + 1);

	vec[0] = 1;
	vec[1] = vec[2] = 0;

	for (int i = 3; i <= S; i++) {
		count += vec[i - 3];
		count %= mod;
		vec[i] = count;
	}

	return count;
}




int main() {
	ll S;

	cin >> S;

	cout << mycalc(S);
}
