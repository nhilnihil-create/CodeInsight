#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define u(x, a, b) for(ll x = a; x < b; x++)
#define d(x, a, b) for(ll x = a; x > b; x--)

typedef long long ll;
typedef long double ld;

#define MAXI 100010
#define MOD 1000000007

int main(){
	string s, t;
	cin >> s >> t;
	ll cnt = 0;
	u(one, 0, 3){if(s[one]==t[one]){cnt++;}}
	
	cout << cnt;
}