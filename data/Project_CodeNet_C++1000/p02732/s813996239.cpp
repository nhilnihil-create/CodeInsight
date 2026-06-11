#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> ball;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ball[A[i]]++;
    }

    ll sum = 0;
    for (auto num : ball) {
        if (num.second >= 2) {
            sum += num.second * (num.second - 1) / 2;
        }
    }

    for (int i = 0; i < N; i++) {
        ll out = sum;
        if (ball[A[i]] > 2) {
            out -= ball[A[i]] - 1;
        } else if (ball[A[i]] == 2) {
            out -= 1;
        }
        cout << out << endl;
    }

    return 0;
}
