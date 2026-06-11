#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    string s, t;
    cin >> s >> t;
    int ret = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i])ret++;
    }
    cout << ret << endl;
    return 0;
}