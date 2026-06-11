#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> P(N, 0);
    for (int i = 0; i < N; ++i) cin >> P[i];
    vector<int> copy(N, 0);
    for (int i = 0; i < N; ++i) copy[i] = P[i];
    sort(copy.begin(), copy.end());
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (cnt > 2) {
            printf("%s\n", "NO");
            return 0;
        }
        if (copy[i] != P[i]) cnt++;
    }
    printf("%s\n", "YES");
    return 0;
}
