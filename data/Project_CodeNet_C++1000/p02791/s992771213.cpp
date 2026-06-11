#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int x;
    int cnt = 0;
    int minx = 100100100;
    rep(i, n) {
        cin >> x;
        if (x <= minx) cnt++;
        minx = min(minx, x);
    }
    cout << cnt << endl;
    return 0;
}