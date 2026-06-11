// 4/25
// 区間スケジューリング問題

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    pair<int, int> itv[100000];

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, l;
        cin >> x >> l;
        itv[i].first = x + l;
        itv[i].second = x - l;
    }

    sort(itv, itv + N);

    int ans = 0, d = -1000000000;

    for (int i = 0; i < N; i++) {
        if (itv[i].second >= d) {
            d = itv[i].first;
            ans++;
        }
    }

    cout << ans << endl;
}