#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
 
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}

int mod = 1e9 + 7;
ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}
 
int main() { 
	//1 2 3 4 5 6 7
	//2 3 4 5 6 7 1
	ll n;
	cin >> n;
	n--;
	cout << (n * (n + 1)) / 2;
}





	
