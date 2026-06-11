#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s.at(0) == s.at(1) && s.at(1) != s.at(2) && s.at(2) == s.at(3)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
