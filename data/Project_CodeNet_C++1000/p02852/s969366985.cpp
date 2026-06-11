#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int re[n+1] = {}, tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0') {
            tmp = 0;
            re[i] = 0;
        }
        else {
            tmp++;
            re[i] = tmp;
        }
    }

    vector<int> res;
    int st = 0;
    bool ok = true;
    while (st < n)
    {
        if(st + m >= n) {
            res.push_back(n - st);
            break;
        }
        else {
            int ex = m - re[st+m];
            if(ex <= 0) {
                ok = false;
                break;
            }
            res.push_back(ex);
            st += ex;
        }
    }
    if(ok) {
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i];
            if(i == res.size()-1) cout << endl;
            else cout << " ";
        }
    }
    else cout << "-1" << endl;
    return 0;
}