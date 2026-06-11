#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int N, K;
int ans;
int p[1000];

int main()
{
    int i;
    cin >> N >> K;

    rep0(i, N)
    {
        cin >> p[i];
    }
    sort(p, p + N);
    rep0(i, K) ans += p[i];

    cout << ans << endl;
    return 0;
}