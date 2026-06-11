#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll a = 11, b = 10, x = 10, lim = 10, mx = 0;
    cin >> a >> b >> x;
    ll i = min(b - 1, x);
    ll A = ((a * i)/b) - a * (i/b);
    cout << A;
    return 0;
}