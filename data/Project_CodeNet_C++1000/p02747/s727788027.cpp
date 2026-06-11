#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string ans = "Yes";
    if(s.size() % 2 == 1) ans = "No";
    else{
        rep(i, s.size()) {
            if(i % 2 == 0) {
                if(s[i] != 'h') ans = "No";
            }
            else {
                if(s[i] != 'i') ans = "No";
            }
        }
    }
    cout << ans << endl;
    return 0;
}