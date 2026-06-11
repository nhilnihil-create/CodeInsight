#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> l(s.size()+1, 0), r(s.size()+1, 0);
    int count = 0;
    sloop(i, 1, s.size()+1) {
        if(s[i-1] == '<') ++count;
        else count = 0;
        l[i] = count;
    }
    count = 0;
    rloop(i, s.size()) {
        if(s[i] == '>') ++count;
        else count = 0;
        r[i] = count;
    }
    long long int ans = 0;
    loop(i, s.size()+1) {
        // cout << l[i] << ' ' << r[i] << endl;
        ans += max(l[i], r[i]);
    }
    cout << ans << endl;
    return 0;
}
