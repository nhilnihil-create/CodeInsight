#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    vector<string> t;
    int n = s.size();
    rep(i, n) {
        string a;
        int st = i;
        while(!(s[i] == 'R' && s[i + 1] == 'L') && i + 1 < n) {
            i++;
        }
        while(s[i + 1] == 'L' && i + 1 < n) {
            i++;
        }
        a = s.substr(st, i - st + 1);
        t.push_back(a);
    }
    
    int m = t.size();
    vector<vector<int>> ans(m);
    rep(i, m) {
        int pt;
        rep(j, t[i].size() - 1) {
            if(t[i][j] == 'R' && t[i][j + 1] == 'L') pt = j;
        }
        int r = (pt + 2) / 2 + (t[i].size() - pt - 1) / 2;
        rep(j, t[i].size()) {
            if(j == pt) ans[i].push_back(r);
            else if(j == pt + 1) ans[i].push_back(t[i].size() - r);
            else ans[i].push_back(0);
        }
    }
    rep(i, m) {
        for(auto x : ans[i]) cout << x << " ";
    }
    cout << '\n';

    return 0;
}