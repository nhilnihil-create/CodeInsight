#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

const int N = int(2e5) + 7;
const int logN = 18;
typedef pair<int, int> pii;

vector<int> st;
int n, a[N], l[N], r[N], rmq[N][logN + 1], lg[N];

int GetMax(int l, int r) {
    int k = lg[r - l + 1];
    return max(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

int Get1(int _l, int _r, int val) {
    int low = _l, high = _r, mid;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(GetMax(mid, _r) > val) low = mid + 1;
        else high = mid - 1;
    }
    if(high == _r && _r < 0) return 0;
    return _r + 1 - high;
}

int Get2(int _l, int _r, int val) {
    int low = _l, high = _r, mid;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(GetMax(_l, mid) > val) high = mid - 1;
        else low = mid + 1;
    }
    if(low == _l && _l > n + 1) return 0;
    return low - _l + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; rmq[i][0] = a[i];
        if((1 << (lg[i - 1] + 1)) == i) lg[i] = lg[i - 1] + 1;
        else lg[i] = lg[i - 1];
    }
    for(int j = 1; j <= logN; ++j) {
        for(int i = 1; i <= n; ++i) {
            rmq[i][j] = max(rmq[i][j - 1], rmq[min(i + (1 << (j - 1)), n)][j - 1]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        while(st.size() && a[st.back()] <= a[i]) st.pop_back();
        if(st.size()) l[i] = st.back();
        else l[i] = 0;
        st.pb(i);
    } st.clear();
    for(int i = n; i >= 1; --i) {
        while(st.size() && a[st.back()] <= a[i]) st.pop_back();
        if(st.size()) r[i] = st.back();
        else r[i] = n + 1;
        st.pb(i);
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        //cout << Get1(1, l[i] - 1, a[i]) * (r[i] - i) << ' ' << Get2(r[i] + 1, n, a[i]) * (i - l[i]) << '\n';
        res += (Get1(1, l[i] - 1, a[i]) * (r[i] - i) + Get2(r[i] + 1, n, a[i]) * (i - l[i])) * a[i];
    }
    cout << res;
}
