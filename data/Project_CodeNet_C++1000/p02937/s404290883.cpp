#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    string s, t; cin >> s >> t;
    ll ans = 0;

    map<char, vector<int>> d;
    rep(i, s.size()){
        d[s.at(i)].push_back(i);
    }
    
    ll now = -1;
    ll loop = 0;
    rep(i, t.size()){
        if(!d.count(t.at(i))){
            cout << -1 << endl;
            return 0;
        }
        if(now>=d.at(t.at(i)).at(d.at(t.at(i)).size()-1)){
            loop++;
            now = d.at(t.at(i)).at(0);
            continue;
        }
        auto iter = upper_bound(ALL(d.at(t.at(i))), now);
        now = *iter;
    }
    ans += loop*s.size() + now + 1;
    cout << ans << endl;
}