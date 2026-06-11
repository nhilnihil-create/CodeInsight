#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;
    int x;
    cin >> x;
    int yen500 = 0, yen5 =0;
    yen500 = x / 500;
    x -= (yen500 * 500);
    yen5 = x / 5;
    int ans = (yen500 * 1000 )+( yen5 * 5);
    cout << ans << "\n";
}
