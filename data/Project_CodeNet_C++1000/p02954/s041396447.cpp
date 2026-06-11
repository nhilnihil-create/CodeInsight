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

vector<ll> primes;

int main(){
	string s;
	cin >> s;
	
	ll n = s.size();

	vector<ll> rlswitch;
	ll cle = 1;
	
	u(one, 1, n){
		if(s[one]==s[one-1]){cle++;}
		else{rlswitch.push_back(cle); cle = 1;}
	}
	rlswitch.push_back(cle);
	
	ll ans[n] = {0};
	ll cpos = 0;
	ll cdir = 1; //1 is to right, -1 is to left
	
	u(one, 0, rlswitch.size()){
		if(cdir==1){
			ll x = rlswitch[one];
			cpos += x;
			ll small = x/2;
			ans[cpos] += small;
			ans[cpos-1] += x-small;
			cdir = -1;
		}
		else{
			ll x = rlswitch[one];
			ll small = x/2;
			ans[cpos-1] += small;
			ans[cpos] += x-small;
			cpos += x;
			cdir = 1;
		}
	}


	u(one, 0, n){cout << ans[one] << ' ';}
}
