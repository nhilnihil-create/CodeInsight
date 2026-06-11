#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
const int N = 10;
int h, w, k, res;
char a[N][N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> h >> w >> k;
    for (int i = 1; i <= h; ++i) for (int j = 1; j <= w; ++j) cin >> a[i][j];
    for (int i = 0; i < (1 << h); ++i)
    for (int j = 0; j < (1 << w); ++j) {
        int cnt = 0;
        for (int i1 = 1; i1 <= h; ++i1) if (((1 << (i1 - 1)) & i) == 0)
        for (int j1 = 1; j1 <= w; ++j1)
            if (a[i1][j1] == '#' && (((1 << (j1 - 1)) & j) == 0))
                ++cnt;
        if (cnt == k) ++res;
    }
    cout << res;
    return 0;
}
