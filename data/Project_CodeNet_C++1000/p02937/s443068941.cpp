#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string s,t;
    cin >> s >> t;

    vector<vector<int>> A(26,vector<int>(0));

    rep(i,s.size()) {
        int tmp = (int) s[i] - 'a';
        A[tmp].push_back(i);
    }
    set<int> S;
    rep(i,t.size()) {
        int tmp = (int) t[i] - 'a';
        S.insert(tmp);
    }

    bool b = true;
    for (auto tmp: S) {
        if (A[tmp].size()==0) {
            b = false;
        }
    }
    if (!b) {
        cout << -1 << endl;
    }
    else {
        ll ans = 0;
        ll is,it;
        is = it = 0;
        is = -1;
        while(1) {
            auto tmp = A[t[it]-'a'];
            int idx = lower_bound(tmp.begin(),tmp.end(),is+1) - tmp.begin();
            if (idx==tmp.size()) {
                is = -1;
                ans+=s.size();
            }
            else {
                is = tmp[idx];
                it++;
            }
            if (it==t.size()) {
                ans += is+1;
                break;
            }            
        }
        cout << ans << endl;
    }
}
