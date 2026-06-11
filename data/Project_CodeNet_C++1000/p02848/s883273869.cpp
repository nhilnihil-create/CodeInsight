#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll n; cin >> n;
	string s;
	cin >> s;	
	for(int i = 0; i < s.size(); ++i){
		s[i] = ((s[i] - 'A') + n) + 'A';
		s[i] = ((s[i] - 'A') % 26) + 'A';
	}
	cout << s;
	return 0;	
}