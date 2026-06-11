#include <set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    set<string> dict;
    int n;
    cin >> n;
    for (int i; i < n; ++i) {
        string c, s;
        cin >> c >> s;
        if (c == "insert") {
            dict.insert(s);
        } else if (c == "find") {
            if (dict.find(s) != dict.end()) {
                cout << "yes";
            } else {
                cout << "no";
            }
            cout << "\n";
        }
    }

    return 0;
}