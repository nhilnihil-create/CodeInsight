#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll N, Q;
    cin >> N >> Q;
    vector<tuple<bool, ll, vector<ll>>> A(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        get<2>(A[a]).push_back(b);
        get<2>(A[b]).push_back(a);
    }
    rep(i, Q) {
        ll p, x;
        cin >> p >> x;
        get<1>(A[p - 1]) += x;
    }
    stack<ll> st;
    st.push(0);
    while(!st.empty()) {
        ll current = st.top();
        st.pop();
        get<0>(A[current]) = true;
        iter(j, get<2>(A[current])) {
            if(!get<0>(A[j])) {
                get<1>(A[j]) += get<1>(A[current]);
                st.push(j);
            }
        }
    }
    iter(i, A) cout << get<1>(i) << endl;
    return 0;
}
