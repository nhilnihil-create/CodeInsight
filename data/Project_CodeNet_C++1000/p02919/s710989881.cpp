#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n;
    cin >> n;
    vector<pii> p(n);
    REP(i,n){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.rbegin(),p.rend());
    multiset<int32> st;
    st.insert(-1);
    st.insert(-1);
    st.insert(n);
    st.insert(n);
    st.insert(p[0].second);
    int64 ans = 0;
    FOR(i,1,n){
        auto iter = st.lower_bound(p[i].second);
        int32 l1 = *(--(--iter));
        int32 l2 = *(++iter);
        int32 r1 = *(++iter);
        int32 r2 = *(++iter);
        // cout << p[i].first << " " << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        ans += p[i].first * ((l2-l1) * (r1-p[i].second) + (p[i].second-l2) * (r2-r1));
        st.insert(p[i].second);
    }
    ANS(ans);
    return 0;
}