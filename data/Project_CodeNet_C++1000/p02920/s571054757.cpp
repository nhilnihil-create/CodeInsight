#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, t;

int main() {
    cin >> n;
    int N = 1;
    int a = 2;
    int b = n;
    while (b) {
        if (b & 1) {
            N *= a;
        }
        a = a * a;
        b >>= 1;
    }
    int mx = 0;
    multiset<int> st;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        st.insert(t);
        mx = max(mx, t);
    }
    vector<int> v(N);
    v[0] = mx;
    int len = 1;
    st.erase(st.find(mx));
    while (len < N) {
        int j = len;
        for (int i = 0; i < len; ++i) {
            auto it = st.lower_bound(v[i]);
            if (it == st.begin()) {
                cout << "No" << endl;
                exit(0);
            }
            --it;
            v[j++] = *it;
            st.erase(it);
        }
        len *= 2;
    }
    cout << "Yes" << endl;
    return 0;
}
