#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, n;
    cin >> h >> n;
    int a, tot = 0;
    rep(i, n) {
        cin >> a;
        tot += a;
    }
    if (tot >= h) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}