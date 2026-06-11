#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

namespace std {
	#define u(x, a, b) for(ll x = a; x < b; x++)
	#define d(x, a, b) for(ll x = a; x > b; x--)
}

typedef long long ll;
typedef long double ld;

#define MAXI 100010
#define MOD 1000000007

int main(){
	ll n;
	cin >> n;
	
	string s;
	cin >> s;
	ll num = 1;
	u(one, 1, n){
		if(s[one]!=s[one-1]){num++;}
	}
	
	cout << num;
}