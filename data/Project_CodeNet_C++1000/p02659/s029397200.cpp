#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a, ans;
    long double b;
    cin >> a >> b;
    b *= 1000;
    ans = (a * b)/1000;
    cout << ans << endl;
    return 0;
}