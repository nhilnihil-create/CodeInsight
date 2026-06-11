#include <bits/stdc++.h>

//~ #pragma GCC optimize("O3")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

bool is_palindrome(string s) {
	string t(s.rbegin(), s.rend());
	return s == t;
}

void solve(){
	string s;
	cin >> s;
	bool is;
	int n = s.size();
	is = is_palindrome(s) && is_palindrome(s.substr(0, (n-1)/2)) && is_palindrome(s.substr((n+1/2)));
	
	cout << (is ? "Yes" : "No");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
