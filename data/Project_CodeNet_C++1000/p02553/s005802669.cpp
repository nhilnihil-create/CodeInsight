#include <iostream>
#include <algorithm>

#define endl '\n'
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve()
{
    int m, n, i, j, k, l;

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    ll r1, r2, r3, r4;

    r1 = (ll)a*c;
    r2 = (ll)a*d;
    r3 = (ll)b*c;
    r4 = (ll)b*d;

    r1 = max(r1, r2);
    r3 = max(r3, r4);

    cout << max(r1, r3);




}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int t; cin >> t; while(t--){
        solve();
//    }
    return 0;
}
