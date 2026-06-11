#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,string>> sub(m);
    rep(i,m) cin >> sub[i].first >> sub[i].second;

    int ac = 0, pena = 0;
    map<int,int> mp;
    rep(i,m) {
        int p = sub[i].first;
        string s = sub[i].second;
        if(mp[p] == -1) continue;
        if(s == "WA"){
            mp[p]++;
        } else {
            ac++;
            pena += mp[p];
            mp[p] = -1;
        }
    }
    cout << ac << " " << pena << endl;
}
