
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
unordered_map<string, int> mp;
ll res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        if (mp.count(s))
            res += mp[s];
        ++mp[s];
    }
    cout << res << endl;

    return 0;
}

