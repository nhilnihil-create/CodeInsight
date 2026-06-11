#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	string s; cin >> s;
	if(s[2]==s[3] && s[4]==s[5]){
		cout << "Yes" << endl;
		return 0;
	}else{
		cout << "No" << endl;
	}
	return 0;
}