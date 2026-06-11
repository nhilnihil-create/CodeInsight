#include <bits/stdc++.h>
#define MAXN 2550
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> id(N+1);

    for (int i=1; i<=N; i++){
        int aux;
        cin >> aux;
        id[aux] = i;
    }

    multiset<int> st;
    ll ans = 0;
    st.insert(0);
    st.insert(0);
    st.insert(N+1);
    st.insert(N+1);


    for (int n = N; n >=1; n--){
        int i = id[n];
        auto l = st.upper_bound(i);
        auto r = l;
        ll x = *(--l), y = *(--l), w = *(r), z = *(++r);

        ans += n*((x - y)*(w - i) + (i - x)*(z - w));
        st.insert(i);
    }

    cout << ans << endl;
    return 0;
}