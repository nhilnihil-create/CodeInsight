#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main()
{   
    string s, res, res2;
    int s_max, cnt = 0;
    map<string, int> mp;

    while (cin >> s) {
        if (s_max < s.size()) {
            s_max = s.size();
            res = s;
        }

        mp[s]++;
    }

    for (const auto &x: mp) {
        if (cnt < x.second) {
            cnt = x.second;
            res2 = x.first;
        }
    }

    cout << res2 << " " << res << endl;
    
}
