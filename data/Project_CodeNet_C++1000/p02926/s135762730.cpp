#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<long long> &a, const vector<long long> &b) {
    return atan2(a[1], a[0]) < atan2(b[1], b[0]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<long long>> coords;
    for (int i = 0; i < N; i++) {
        vector<long long> coord(2);
        cin >> coord[0] >> coord[1];
        coords.push_back(coord);
    }

    sort(coords.begin(), coords.end(), compare);

    long long maxDist = 0;
    for (int i = 0; i < N; i++) {
        long long x = 0, y = 0;
        for (int j = i; j < i + N; j++) {
            x += coords[j % N][0];
            y += coords[j % N][1];
            maxDist = max(maxDist, x * x + y * y);
        }
    }
    cout << fixed << setprecision(11) << sqrt(maxDist) << '\n';

    return 0;
}