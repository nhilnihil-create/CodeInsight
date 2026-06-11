#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> data;
    rep(i, n+1) {
        if (s[i]=='0') data.insert(i);
    }
    vector<int> ans;
    int now = n;
    while (now!=0) {
        auto it = data.lower_bound(now-m);
        if (now-*it==0) {
            cout << "-1" << endl;
            return 0;
        } 
        ans.push_back(now-*it);
        now = *it;
    }
    
    rep(i, ans.size()) {
        cout << ans[ans.size()-1-i] << " ";
    }
    cout << endl;

    return 0;
}
