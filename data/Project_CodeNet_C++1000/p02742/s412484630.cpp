#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll h, w;
    cin >> h >> w;
 
    ll ans = h * w / 2 + h * w % 2;
    cout << (h == 1 || w == 1 ? 1 : ans) << endl;
    return 0;
}