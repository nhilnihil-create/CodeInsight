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
    vector<int> p(n);
    vector<int> pos(n);
    rep(i, n) {
        cin >> p[i];
        pos[p[i]-1] = i;
    }
    
    set<int> s;
    ll ans = 0;

    for (int i=n-1; i>=0; i--) {
        int x = pos[i];
        if (s.size()==0) {
            s.insert(x);
            continue;
        }
        auto it = s.upper_bound(x);
        ll l1, l2, r1, r2;
        if (it!=s.end()) {
            r1 = *it;
            it++;
            if (it!=s.end()) {
                r2 = *it;
            }
            else {
                r2 = n;
            }
            it--;
        }
        else {
            r1 = n;
            r2 = n;
        }
        if (it!=s.begin()) {
            it--;
            l2 = *it;
            if (it!=s.begin()) {
                it--;
                l1 = *it;
            }
            else {
                l1 = -1;
            }
        }
        else {
            l1 = -1;
            l2 = -1;
        }
        ans += (l2-l1) * (r1-x) * (i+1);
        ans += (r2-r1) * (x-l2) * (i+1);
        s.insert(x);
        //debug(ans);
    }
     
    
    
    
    
    cout << ans << endl;
    return 0;
}
