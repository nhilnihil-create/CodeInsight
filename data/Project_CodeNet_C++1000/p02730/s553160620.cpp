#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    bool flag = true;

    for (int i=0; i<n/2; i++)
        if (s[i] != s[n-1-i])
            flag = false;

    for (int i=0; i<n/4; i++) {
        if (s[i] != s[n/2-1-i])
            flag = false;
        if (s[n/2+1+i] != s[n-1-i])
            flag = false;
    }

    cout << (flag ? "Yes" : "No") << "\n";
}
