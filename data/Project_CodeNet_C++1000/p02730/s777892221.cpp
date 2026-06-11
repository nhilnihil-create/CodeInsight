#include<bits/stdc++.h>	
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


ll arr[maxsize];
vector<ll> v(maxsize);
map<ll, ll> m;	

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return  a * b / gcd(a, b);
}

bool is_palindrome(string s) {
	string t(s.rbegin(), s.rend());
	return t == s;
}
 
 
void solve() {
	string s;
	bool flag = true;
	cin >> s;
	int n = s.length();
	if(is_palindrome(s) && is_palindrome(s.substr(0, (n - 1) / 2)) && is_palindrome(s.substr((n + 1) / 2)))
	cout << "Yes" << endl;
	else cout << "No" << endl;
}


	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}




