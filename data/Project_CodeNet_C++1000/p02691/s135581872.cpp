#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

struct triple {
    ll aa;
    ll bb;
    ll cc;
    bool operator<(const triple &tt) {
        if (aa != tt.aa) {
            return (aa < tt.aa);
        }
        if (bb != tt.bb) {
            return (bb < tt.bb);
        }
        return cc < tt.cc;
    }
    bool operator==(const triple &tt) {
        return (aa == tt.aa &&
                bb == tt.bb &&
                cc == tt.cc);
    }
    bool operator>(const triple &tt) { return !(*this == tt) && !(*this < tt); }
    bool operator!=(const triple &tt) { return !(*this == tt); }
    bool operator>=(const triple &tt) { return (*this == tt) || (*this > tt); }
    bool operator<=(const triple &tt) { return (*this == tt) || (*this < tt); }
};

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> RA(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++) {
        RA[i] = A[N - i - 1];
    }

    ll result = 0;

    map<ll, vector<ll>> party;
    for (ll i = 0; i < N; i++) {
        ll pt = A[i] - i;
        party[pt].push_back(i);
    }
    for (ll i = 0; i < N; i++) {
        ll tgtp = -i - A[i];
        if (!party.count(tgtp)) {
            continue;
        }
        ll cnt = party[tgtp].end() - upper_bound(party[tgtp].begin(), party[tgtp].end(), i);
        //   print(i + 1, cnt);
        result += party[tgtp].end() - upper_bound(party[tgtp].begin(), party[tgtp].end(), i);
    }

    // map<ll, vector<ll>> rparty;
    // for (ll i = 0; i < N; i++) {
    //     ll pt = RA[i] - i;
    //     rparty[pt].push_back(i);
    // }
    // for (ll i = 0; i < N; i++) {
    //     ll tgtp = -i - RA[i];
    //     if (!party.count(tgtp)) {
    //         continue;
    //     }
    //     //result += rparty[tgtp].end() - upper_bound(rparty[tgtp].begin(), rparty[tgtp].end(), i);
    // }
    print(result);
}
