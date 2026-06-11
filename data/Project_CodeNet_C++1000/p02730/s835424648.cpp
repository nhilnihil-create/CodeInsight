#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    string a = s.substr(0,(n-1)/2);
    string b = s.substr((n + 1) / 2, (n - 1) / 2);

    if(a != b) {
        cout << "No" << "\n";
        return 0;
    }
    reverse(all(a));
    if(a == b)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}
