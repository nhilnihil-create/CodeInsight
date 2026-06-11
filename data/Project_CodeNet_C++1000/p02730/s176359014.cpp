#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ins insert
#define eb emplace_back
#define endl '\n'
#define ll long long
#define ld long double
#define vl vector<ll>
#define tc ll t; cin >> t; while (t--)2 2
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define sz(c) (ll) c.size()
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define trav(x,c) for(auto &x : c)
#define _for(i,a,n) for(ll i = a ; i < n ; ++i)
#define _rfor(i,a,n) for(ll i = n-1 ; i >= a ; --i)
#define dx(x) cout << #x << ": " << x << endl;
#define dc(c) trav(x,c) cout << x << " "; cout << endl;
#define godspeed ios::sync_with_stdio(0); cin.tie(0);

bool is_palin(string s) {
	string t = s;
	reverse(all(t));
	return (s == t) ? 1 : 0;
}

string palin(string s) {
	string t;
	ll n = sz(s);
	t = s;
	if(!is_palin(t)) return "No";

	t = s.substr(0,(n-1)/2);
	if(!is_palin(t)) return "No";

	t = s.substr((n+3)/2,n - 1 - ((n+3)/2));
	if(!is_palin(t)) return "No";

	return "Yes";

}

int main() {
    godspeed;
 	string s; cin >> s;
 	cout << palin(s);
}