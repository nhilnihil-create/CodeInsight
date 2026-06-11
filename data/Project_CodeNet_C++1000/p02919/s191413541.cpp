#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define INF LONG_LONG_MAX
#define MOD 1000000007
#define yn(f) cout << (f ? "Yes" : "No") << endl;
#define YN(f) cout << (f ? "YES" : "NO") << endl;

int n,ans;
vector<pair<int,int>> v;
multiset<int> s;

signed main() {
    cin >> n;
    rep(i,n) {
        int a;
        cin >> a;
        v.pb(mp(a,i));
    }
    sort(rall(v));
    s.insert(-1);
    s.insert(-1);
    s.insert(n);
    s.insert(n);
    s.insert(v[0].se);
    rep11(i,n) {
        int a = v[i].fi, idx = v[i].se;
        int L,l,r,R;
        auto itr = ----s.upper_bound(idx);
        L = *itr;++itr;
        l = *itr;++itr;
        r = *itr;++itr;
        R = *itr;

        ans += a*((idx-l)*(R-r) + (r-idx)*(l-L));

        s.insert(idx);
    }
    cout << ans << endl;
}


