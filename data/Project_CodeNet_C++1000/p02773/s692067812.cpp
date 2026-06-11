#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int n; cin >> n;
    map<string,int> s;
    string tmp;
    rep(i,n) {
        cin >> tmp;
        s[tmp]++;
    }
    int m = 1;
    for(pair<string, int> x: s) {
        m = max(m, x.second);
    }
    vector<string> ans;
    for(pair<string, int> x: s) {
        if(x.second == m) ans.push_back(x.first);
    }
    sort(ans.begin(), ans.end());
    for(string x: ans) cout << x << endl;
}