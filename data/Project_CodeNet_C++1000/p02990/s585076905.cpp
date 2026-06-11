#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 4e3 + 5, mod = 1e9 + 7;
int n, k, p[N][N];
int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
void pascal(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            p[i][j] = ((j)? add(p[i - 1][j - 1] , p[i - 1][j]) : 1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pascal();
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cout << mul(p[n - k + 1][i], p[k - 1][i - 1]) << '\n';
    return 0;
}
