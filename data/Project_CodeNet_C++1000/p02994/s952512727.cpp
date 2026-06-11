#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 200005

int n , a;

int main()
{
    _FastIO;
    cin >> n >> a;
    int l = a;
    int r = a + n - 1;
    int eat;
    if(r <= 0)  eat = r;
    else    if(l >= 0) eat = l;
    else eat = 0;
    int ans = (r + l) * (r - l + 1) / 2 - eat;
    cout << ans << endl;
    return 0;
}
