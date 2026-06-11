#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main() {
    long long N;
    long long ans = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        ans += (i+1) * (N-i);
    }

    for (int i = 1; i < N; ++i) {
        int f;
        int t;
        cin >> f >> t;
        if (t < f) {
            swap(t, f);
        }
        // cout << "DEBUG " << ans << endl;
        ans -= f * (N-t+1);
    }

    cout << ans << endl;

    return 0;
}