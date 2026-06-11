#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(a + b >= k) cout << min(a, k);
    else{
        k -= a;
        k -= b;
        cout << a - k;
    }
    return 0;
}