#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = n / 2;
    if(n % 2 == 0)
        ans --;
    cout << ans;


    return 0;
}
