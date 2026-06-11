#include <iostream>
#include <vector>
using namespace std;

int N; long long D; vector<long long> L;
void input()
{
    cin >> N >> D;
    L.resize(N);
    for (int i = 0; i < N; ++i){
        long long x,y; cin >> x >> y;
        L[i] = x*x + y*y;
    }
}

void solve()
{
    int sum = 0;
    for (int i = 0; i < N; ++i){
        if (L[i] <= D*D) ++sum;
    }
    cout << sum << endl;
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