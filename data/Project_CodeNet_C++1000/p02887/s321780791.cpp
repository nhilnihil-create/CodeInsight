#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, idx = 0;
    string s;
    cin >> n >> s;
    while ((unsigned int) idx + 1 < s.size()) {
        if (s.at(idx) == s.at(idx + 1)) {
            s.erase(idx, 1);
        } else {
            idx++;
        }
    }
    cout << s.size() << endl;
}
