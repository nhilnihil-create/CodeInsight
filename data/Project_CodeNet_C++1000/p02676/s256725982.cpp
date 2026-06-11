#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int k;
    string s;
    cin >> k;
    cin >> s;

    if (s.size() <= k) cout << s << endl;
    else {
        s.erase(k);
        cout << s << "..." << endl;
    }
}