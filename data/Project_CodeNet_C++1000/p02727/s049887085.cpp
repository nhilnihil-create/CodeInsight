#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A);
    vector<ll> q(B);
    vector<ll> r(C);
    for (ll i = 0; i < A; i++) {
        cin >> p[i];
    }
    for (ll i = 0; i < B; i++) {
        cin >> q[i];
    }
    for (ll i = 0; i < C; i++) {
        cin >> r[i];
    }

    vector<ll> aka(X);
    sort(p.begin(), p.end(), [](ll a, ll b) { return a > b; });
    for (ll i = 0; i < X; i++) {
        aka[X - i - 1] = p[i];
    }

    vector<ll> midori(Y);
    sort(q.begin(), q.end(), [](ll a, ll b) { return a > b; });
    for (ll i = 0; i < Y; i++) {
        midori[Y - i - 1] = q[i];
    }

    //sort(r.begin(), r.end());
    sort(r.begin(), r.end(), [](ll a, ll b) { return a > b; });
    ll ai = 0;
    ll mi = 0;
    for (ll ri = 0; ri < r.size(); ri++) {
        ll ax = aka[ai];
        ll mx = midori[mi];
        ll rx = r[ri];
        // if (ax > rx && ai < aka.size() - 1) {
        //     ai++;
        // }
        // if (mx > rx && mi < midori.size() - 1) {
        //     mi++;
        // }
        if (ax < mx && ax < rx) {
            aka[ai] = rx;
            if (ai < aka.size() - 1) {
                ai++;
            }
        } else if (mx < rx) {
            midori[mi] = rx;
            if (mi < midori.size() - 1) {
                mi++;
            }
        }
    }
    ll total = 0;
    for (ll ak : aka) {
        total += ak;
    }
    for (ll md : midori) {
        total += md;
    }
    print(total);
}
