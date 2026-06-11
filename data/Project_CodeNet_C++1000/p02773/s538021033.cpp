#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,string>;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        if(mp.count(s)) {
            mp.at(s)++;
        }
        else {
            mp[s] = 1;
        }
    }
    
    vector<P> vt;
    for(auto p : mp) {
        P vi = make_pair(p.second, p.first);
        vt.push_back(vi);
    }
    sort(vt.begin(), vt.end());
    reverse(vt.begin(), vt.end());
    int i = 0;
    int m = vt.at(i).first;
    vector<string> ans;
    while(i < vt.size() && vt.at(i).first == m) {
        ans.push_back(vt.at(i).second);
        i++;
    }
    reverse(ans.begin(), ans.end());
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}