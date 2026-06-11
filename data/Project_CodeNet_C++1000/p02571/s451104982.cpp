#include <bits/stdc++.h>
using namespace std;

int main() {
 	string s, t;
 	cin >> s >> t;
 	int x = s.size(), y = t.size();
 	int ans = 0;
 	for(int i = 0; i < x - y + 1; i++) {
        int lol = 0;
        for(int j = 0; j < y; j++) {
            if(s[i + j] == t[j]) {
                lol++;
            }
        }
        ans = max(ans, lol);
 	}
 	cout << y - ans << endl;
}
