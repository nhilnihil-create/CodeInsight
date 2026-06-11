#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k,t,ans;
    cin >> n;
    ans = (n + 999) / 1000;
    ans *= 1000;
    ans -= n;
    cout << ans << '\n';
    return 0;
}