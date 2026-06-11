#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
const long long INF = 100000000000000000;

/* マンハッタン距離の典型らしい */
void solve()
{
    int N; cin >> N;
    vector<long long > z(N),w(N);
    for (int i = 0; i < N; ++i){
        int x,y; cin >> x >> y;
        z[i] = x+y;
        w[i] = x-y;
    }
   sort(z.begin(),z.end());
   sort(w.begin(),w.end());
   cout << max(z[N-1]-z[0],w[N-1]-w[0]) << endl;
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