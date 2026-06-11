#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;




int main(){
	ll n;
	string s;
	cin >> n;
	cin >> s;
	
	int len = s.size();
	ll r = 0;
	ll g = 0;
	ll b = 0;
	for ( int i = 0; i < len; i++ ){
		if ( s[i] == 'R' ) r++;
		if ( s[i] == 'G' ) g++;
		if ( s[i] == 'B' ) b++;
	}
	
	ll count = 0;
	for ( int i = 0; i < len-2; i++ ){
		for ( int j = 1; i+j*2 < len; j++ ){
			if ( s[i] + s[i+j] + s[i+j*2] == 'R'+'G'+'B' )
				count++;
		}
	}
	
	cout << r*g*b-count << endl;
	
	return 0;
}


