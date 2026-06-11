#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<int> s(1<<n);
    rep(i, 1<<n) cin >> s[i];
    sort(s.begin(), s.end());
    map<int, int> mp;
    vector<int> now;
    now.push_back(s.back());
    string ans = "Yes";
    bool ok = true;

    rep(i, (1<<n)-1) {
        mp[s[i]]++;
    }
    rep(i, n) {
        vector<int> ad;
        for (int e: now) {
            auto it = mp.lower_bound(e);
            if (it==mp.begin()) {
                ok = false;
                break;
            }
            it--;
            ad.push_back(it->first);
            (it->second)--;
            if (it->second==0) mp.erase(it->first);
        }
        if (!ok) break;
        for (int e: ad) {
            now.push_back(e);
        }
    }

    if (!ok) {
        ans = "No";
    } 
    
    
    cout << ans << endl;
    return 0;
}
