#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n, p;
string s;

int main(){
	cin >> n >> p;
	cin >> s;
	int len = s.length();
	
	ll result = 0;
	if ( p == 2 || p == 5 ){
		for ( int i = len-1; i >= 0; i-- ){
			if ( (s[i]-'0') % p == 0 )
				result += i+1;
		}
	}
	else {
		ll x = 0;
		ll mul = 1;
		map<int,ll> m;
		m[0] = 1;
		
		for ( int i = len-1; i >= 0; i-- ){
			x = (x + (s[i]-'0')*mul) % p;
			m[x]++;
			mul = mul * 10 % p;
		}
		
		for ( auto it : m ){
			//cout << it.first << " " << it.second << endl;
			result += it.second * (it.second-1) / 2;
		}
	}
	
	cout << result << endl;
	
	return 0;
}

