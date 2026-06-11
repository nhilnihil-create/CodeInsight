#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
vector<P> ret;

void until_plus(multiset<ll> &st) {
    while (st.size() > 2) {
        auto litr = st.begin(); auto ritr = st.end();
        --ritr;
        ll l = *litr; ll r = *ritr;
        if (r >= 0 && *prev(ritr) < 0) break;
        st.erase(litr); st.erase(ritr);
        ret.push_back({l,r});
        st.insert(l-r);
    }
}

void only_plus(multiset<ll> &st) {
    while (st.size() > 2) {
        auto litr = st.begin(); auto ritr = st.end();
        --ritr;
        ll l = *litr; ll r = *ritr;
        st.erase(litr); st.erase(ritr);
        ret.push_back({r,l});
        st.insert(r-l);
    }
}

void predeal(multiset<ll> &st) {
    while (st.size() > 2) {
        auto litr = st.begin(); auto ritr = st.end();
        --ritr;
        ll l = *litr; ll r = *ritr;
        st.erase(litr); st.erase(ritr);
        ret.push_back({r,l});
        st.insert(r-l);
    }
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    multiset<ll> st;
    bool min = true;
    rep(i,n) {
        ll a; cin>>a;
        if (a>0) min = false;
        st.insert(a);
    }

    if (min) predeal(st);
    until_plus(st);
    only_plus(st);

    auto litr = st.begin(); auto ritr = st.end();
    --ritr;
    ll l = *litr; ll r = *ritr;
    ret.push_back({r,l});
    ll ans = r-l;

    cout << ans << endl;
    for (auto &&e: ret) {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}

/*



*/