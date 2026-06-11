#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;

using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> p(n);
    unordered_map<ll, ll> mp;
    set<ll> s;
    rep(i, n) {
        cin >> p[i];
        mp[p[i]] = i;
        s.insert(p[i]);
    }

    set<ll> idx;
    ll ans = 0;

    while(!s.empty()) {
        ll now = *s.rbegin();
        s.erase(now);

        ll i = mp[now];
        vector<ll> l(2, -1), r(2, n);

        {
            auto itr = idx.lower_bound(i);
            rep(j, 2) {
                if (itr == idx.end()) break;
                r[j] = *itr;
                itr++;
            }

        }

        {
            auto itr = idx.lower_bound(i);
            rep(j, 2) {
                if (itr == idx.begin()) break;
                itr--;
                l[j] = *itr;
            }
        }

        ll l1 = i - l[0], l2 = l[0] - l[1];
        ll r1 = r[0] - i, r2 = r[1] - r[0];
        ans += (l1 * r2 + l2 * r1) * now;

        idx.insert(i);
    }

    cout << ans << '\n';


}