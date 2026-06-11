#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#include <ctime>
using namespace std;

int N; vector<int> a;
void input()
{
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
}

void solve()
{
    vector<int> dis(N-1);
    for (int i = 0; i < N-1; ++i) dis[i] = a[0] ^ a[i+1];
    int sum = 0;
    for (int i = 0; i < N-1; ++i) sum ^= dis[i];

    int ans = sum ^ a[0];
    cout << ans << " ";
    for (int i = 0; i < N-1; ++i){
        int ans2 = ans ^ dis[i];
        cout << ans2 << " ";
    }
    cout << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}