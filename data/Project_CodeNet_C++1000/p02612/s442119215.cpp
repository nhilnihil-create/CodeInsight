#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
#define N_MAX 10000
using namespace std;

int N;

int main()
{
    cin >> N;
    int ans = N % 1000 == 0 ? 0 : 1000 - N % 1000;
    cout << ans << endl;
    return 0;
}