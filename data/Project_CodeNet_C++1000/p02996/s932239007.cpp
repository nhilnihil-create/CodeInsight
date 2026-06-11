#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    int A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        v[i] = make_pair(B, A);
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i].second;
        if (sum > v[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}