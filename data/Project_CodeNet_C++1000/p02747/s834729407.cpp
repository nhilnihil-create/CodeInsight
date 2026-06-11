#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.size() % 2) {
        cout << "No\n";
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 && s[i] != 'i' ||
            i % 2 == 0 && s[i] != 'h') {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}   