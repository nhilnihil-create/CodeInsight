#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int N,K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) cin >> p[i];

    sort(p.begin(),p.end());
    int ans = 0;
    for (int i = 0; i < K; ++i) ans += p[i];
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}