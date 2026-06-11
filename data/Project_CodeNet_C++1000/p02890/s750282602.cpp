#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>cnt(N+1, 0);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        cnt[A]++;
    }
    sort(cnt.begin(), cnt.end());
    int sum = 0;
    vector<int>ans(N+1);
    ans[0] = N+1;
    // 取ることのできる回数でループ
    // Kに対して単調減少
    for (int i = 1; i <= N; ++i) {
        auto iter = lower_bound(cnt.begin(), cnt.end(), i);
        sum += cnt.end() - iter;
        ans[i] = sum / i; // ans[i] >= K ならi個取れる
    }
    for (int i = 1; i <= N; ++i) {
        auto iter = upper_bound(ans.begin(), ans.end(), i, greater<int>());
        cout << iter - ans.begin() - 1 << "\n";
    }
    return 0;
}