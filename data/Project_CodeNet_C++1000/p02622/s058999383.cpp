#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	string s, t;
	cin >> s >> t;
	
	int ans = 0;

	
	for (int i = 0; i < (int) s.size(); ++i) {
		if (s[i] != t[i]) 
			++ans;
		}
	cout << ans;
	
}
