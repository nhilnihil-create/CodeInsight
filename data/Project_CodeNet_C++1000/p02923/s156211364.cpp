#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) cin >> heights[i];
    int res = 0;
    for (int i = 0, j = 0; i < N; i = j) {
        while(j < N && (i == j || heights[j] <= heights[j-1])) ++j;
        res = max(res, j - i - 1);
    }
    cout << res << '\n';
}
