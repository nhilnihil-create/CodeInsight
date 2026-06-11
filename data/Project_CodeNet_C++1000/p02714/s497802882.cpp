#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)

int main()
{
	ll n;
	string s;
	cin >> n >> s;
	ll r = 0, g = 0, b = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'R')
			r++;
		else if (s[i] == 'G')
			g++;
		else if (s[i] == 'B')
			b++;
	}
	
	if (r * g * b == 0){
		cout << "0" << "\n";
		return 0;
	}
	ll d = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1 ; j < n; j++){
			ll k = 2*j-i;
			if (k < n && s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
				d++;
		}
	}
	cout << r * g * b - d;
	return 0;
}