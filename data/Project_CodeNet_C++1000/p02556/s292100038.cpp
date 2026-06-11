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

    long long z_min=INF,z_max=-INF,w_min=INF,w_max=-INF;
    for (int i = 0; i < N; ++i){
        if(z[i]<z_min) z_min = z[i];
        if(z[i]>z_max) z_max = z[i];
        if(w[i]<w_min) w_min = w[i];
        if(w[i]>w_max) w_max = w[i];
    }
    cout << max(z_max-z_min,w_max-w_min) << endl;
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