#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size() - t.size() + 1;
    int min = t.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < int(t.size()); ++j) {
            if (t[j] != s[i+j]) {
                count++;
            }
        }
        if (min > count) {
            min = count;
        }
    }
    cout << min << "\n";
    return 0;
}
