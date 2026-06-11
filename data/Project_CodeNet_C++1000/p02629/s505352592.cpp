#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	ll n; 
	cin >> n;
	string ans = "";
	while(n>0) {
		n--;
		char c = (n%26) + 'a';
		ans = c + ans;
		n/= 26;
	}
	cout << ans << endl;
	
}
