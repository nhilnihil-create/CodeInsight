#include <bits/stdc++.h>


using namespace std;

using ll = long long;


int main() {
    ll N, K, C;
    string S;
    cin >> N >> K >> C;
    cin >> S;

    vector<ll> work_left, work_right;
    for (ll i = S.size() - 1; i >= 0; i--) {
        if (S[i] == 'x')
            continue;
        if (work_right.size() == 0 || *work_right.rbegin() - i > C) {
            work_right.push_back(i);
        }
    }

    for (ll i = 0; i < S.size(); i++) {
        if (S[i] == 'x')
            continue;
        if (*work_right.rbegin() == i) {
            work_right.pop_back();
        }
        ll total = work_left.size() + work_right.size();
        if (work_left.size() > 0 && work_right.size() > 0 && *work_right.rbegin() - *work_left.rbegin() <= C) {
            total--;
        }
        if (total < K) {
            cout << i + 1 << endl;
        }

        if (work_left.size() == 0 || i - *work_left.rbegin() > C) {
            work_left.push_back(i);
        }
    }
}
