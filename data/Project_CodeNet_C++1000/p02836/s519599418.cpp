#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    string s; cin >> s;
    int  n = s.size();
    string left, right;
    left = s.substr(0, n / 2);
    if (n % 2 == 0) {        
        right = s.substr(n / 2);
    }
    else {
        right = s.substr(n / 2 + 1);
    }
    int ans = 0;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != right[right.size() - i - 1]) ans++;
    }
    cout << ans << endl;
    return 0;
}