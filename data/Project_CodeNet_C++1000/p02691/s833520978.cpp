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

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<ll, vector<ll>> party;
    for (ll i = 0; i < N; i++) {
        ll pt = A[i] - i;
        party[pt].push_back(i);
    }

    ll result = 0;
    for (ll i = 0; i < N; i++) {
        ll tgtp = -i - A[i];
        if (party.count(tgtp)) {
            result += party[tgtp].end() - upper_bound(party[tgtp].begin(), party[tgtp].end(), i);
        }
    }
    print(result);
}
