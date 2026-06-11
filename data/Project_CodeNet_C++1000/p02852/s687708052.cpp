#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);



int main() {
    int n,m; cin >> n >> m;
    string s; cin >> s;

    int now = n;
    vector<int> ans;
    while(now != 0) {
        if(now <= m) {
            ans.push_back(now);
            break;
        }
        bool flag = true;
        for(int i=m; i > 0; i--) {
            if(s[now-i] == '0') {
                ans.push_back(i);
                now -= i;
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }


    return 0;
}

