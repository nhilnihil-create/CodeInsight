#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> L(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end()); // L をソートしておく (二分探索に必要)

    long long res = 0;
    
    // a と b を固定
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            // c の動ける範囲の右端を求める
            int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();

            // c の動ける範囲は、[j+1, k)
            res += max(k - (j+1), 0);
        }
    }
    cout << res << endl;
}