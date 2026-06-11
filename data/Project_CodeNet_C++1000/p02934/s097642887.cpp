#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n;
string s;

int main()
{
    _FastIO;
    cout.precision(14);
    cin >> n;
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        double x;
        cin >> x;
        ans += (1.0 * 1.0 / x);
    }
    ans = 1.0 * 1.0 / ans;
    cout << fixed << ans << endl;
    return 0;
}
