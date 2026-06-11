#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<int> p(n), pos(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    ll ans = 0;
    set<int> s;

    for(int i = n-1; i >= 0; i--){
        int index = pos[i];
        s.insert(index);
        vector<int> l(2, -1);
        vector<int> r(2, n);

        auto it = s.find(index);
        rep(j,2){
            if(it == s.begin()) break;
            it--;
            l[j] = *it;
        }

        it = s.find(index);
        rep(j,2){
            it++;
            if(it == s.end()) break;
            r[j] = *it;
        }

        ll cnt = (ll)(index-l[0])*(r[1]-r[0]) + (ll)(r[0]-index)*(l[0]-l[1]);
        ans += cnt*(i+1);
    }
    
    cout << ans << endl;
}