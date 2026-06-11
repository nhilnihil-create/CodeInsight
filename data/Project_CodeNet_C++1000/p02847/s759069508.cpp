#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> a = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int i = 0;
    for (i = 0; i < 7; ++i) {
        if (a[i] == s) break;
    }
    cout << 7 - i << endl;
}
