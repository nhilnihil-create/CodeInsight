#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    int m = max(h, w);
    if(n%m==0) cout << n/m << '\n';
    else cout << n/m+1 << '\n';

    return 0;
}