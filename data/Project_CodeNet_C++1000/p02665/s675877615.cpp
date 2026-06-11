#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<unsigned long long int> A(N + 2, 0);
    vector<pair <unsigned long long int, unsigned long long int>> P(N + 1);
    unsigned long long int ans = 0;
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    bool T = true;
    for (int i = N; i >= 0; --i) {
        unsigned long long int min_t, max_t;
        if (i == N) {
            min_t = A[i];
            max_t = A[i];
            P[i] = make_pair(min_t, max_t);
        }
        else {
            if (P[i + 1].first % 2 == 0) min_t = P[i + 1].first / 2 + A[i];
            else min_t = P[i + 1].first / 2 + 1 + A[i];
            max_t = P[i + 1].second + A[i];
            P[i] = make_pair(min_t, max_t);
        }
        if (i == 0) {
            if (P[i].first != 1) T = false;
        }
    }
    unsigned long long int tmp = 0;
    for (int i = 0; i <= N; ++i) {
        unsigned long long int s = 0;
        if (i == 0) {
            tmp = 1;
        }
        tmp = min(P[i].second, tmp);
        s = tmp;
        tmp  -= A[i];
        tmp *= 2;
        ans += s;
    }
    if (T) cout << ans << endl;
    else cout << -1 << endl;
}