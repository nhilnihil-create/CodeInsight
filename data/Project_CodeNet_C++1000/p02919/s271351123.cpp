#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int a[200010];
    rep(i, N) cin >> a[i];
    rep(i, N) a[i]--;
    int b[200010];
    rep(i, N) b[a[i]] = i;
    multiset<int> st;
    st.insert(-1); st.insert(-1);
    st.insert(N); st.insert(N);
    int ans = 0;
    RREP(i, N - 1, 0) {
        int idx = b[i];
        auto itrL2 = (--(--st.lower_bound(idx)));
        auto itrL1 = --st.lower_bound(idx);
        auto itrR1 = st.lower_bound(idx);
        auto itrR2 = ++st.lower_bound(idx);
        //ans += (i + 1) * (*itr - idx) * (idx - *itr2);
        //cerr << idx << " " << *itr << " " << *itr2 << endl;
        ans += (i + 1) * (*itrL1 - *itrL2) * (*itrR1 - idx);
        ans += (i + 1) * (idx - *itrL1) * (*itrR2 - *itrR1);
        //cerr << *itrL2 << " " << *itrL1 << " " << idx << " " << *itrR1 << " " << *itrR2 << endl;
        st.insert(idx);
    }
    cout << ans << endl;

    return 0;
}
