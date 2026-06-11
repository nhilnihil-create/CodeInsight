#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    string s1 = "";
    string s2 = "";
    cin >> n >> s;
    if (n < s.length() || n % 2 != 0) cout << "No" << endl;
    else {
        for (int i = 0; i < (s.length() / 2); ++i) {
            s1 += s[i];
        }
        for (int j = s.length() / 2; j < s.length(); ++j) {
            s2 += s[j];
        }
        if (s1 == s2) cout << "Yes" << endl;
        else cout << "No" << endl;
//            cout << s2;
    }


}




