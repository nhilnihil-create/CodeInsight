#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll a,b,n;
    cin >> a >> b >> n;
    ll x=min(b-1,n);
    cout << floor(a*x/b) << endl;

    return 0;
}