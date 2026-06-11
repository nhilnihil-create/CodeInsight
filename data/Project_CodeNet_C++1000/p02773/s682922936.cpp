#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> a;
    rep(i,n) {
        string s;
        cin >> s;
        a[s]++;
    }
    int maxv = 0;
    for (const auto& x : a) {
        maxv = max(maxv, x.second);
    }
    for (auto i = a.begin(); i != a.end(); i++) {
        if (i->second == maxv)
            cout << i->first << endl;
    }
    return 0;
}
