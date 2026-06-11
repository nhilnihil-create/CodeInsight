#include <bits/stdc++.h>
using namespace std;

int l, r, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r >> d;
    int ans = 0;
    for(int i = 1; i <= 100; i++)
        ans += (d * i >= l && d * i <= r);
    cout << ans << '\n';
    return 0;
}
