#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

bool is_palindrome(string s) {
	string rev_s = s;
	reverse(all(rev_s));
	return s == rev_s;
}

void solve(){
	string s;
	cin >> s;
	bool is;
	is = is_palindrome(s);
	int n = s.size();
	if(is) is = is_palindrome(s.substr(0, (n-1)/2));
	if(is) is = is_palindrome(s.substr((n+3)/2-1, string::npos));
	
	cout << (is ? "Yes" : "No");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
