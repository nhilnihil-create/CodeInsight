#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<bool> A(N+1, true);
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        A[a] = false;
    }
    vector<long long> ans(N+1, 0);
    ans[0] = 1;
    if (A[1])
    {
        ans[1] = 1;
    }
    
    for (int i = 2; i <= N; i++)
    {
        if (A[i])
        {
            if (A[i-1])
            {
                ans[i] = ans[i-1];
            }
            if (A[i-2])
            {
                ans[i] = (ans[i] + ans[i-2]) % MOD;
            }
        }
    }
    cout << ans[N] << endl;
}

int main() {
    solve();
    return 0;
}