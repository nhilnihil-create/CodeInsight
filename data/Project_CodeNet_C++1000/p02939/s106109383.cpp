#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	string s;
	cin >> s;
	int ans = 1;
	int ls = 1;
	for(int i = 1; i < s.size(); i++) {
		// cout << i << " ";
		if(ls == 2 || s[i] != s[i - 1]) {
			ans++;
			ls = 1;
			// cout << i << endl;
			continue;
		}
		if(s[i] == s[i - 1]) {
			if(i != s.size() - 1)
				ans += 1;
			ls = 2;
			i++;
		}
	}
	cout << ans << endl;
	
    return 0;
}