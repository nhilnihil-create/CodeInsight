#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;
    while (n--) {
        string t;
        cin >> t;
        s.insert(t);
    }

    cout << s.size();

    return 0;
}
