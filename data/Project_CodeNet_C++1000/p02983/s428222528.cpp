#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int l , r;
    cin >> l >> r;

    r = min(r , l + 2019);

    int mn = 1e9;
    for (int i = l ;i < r ;i++)
        for (int j = i + 1 ;j <= r ;j++)
            mn = min(1ll * mn , (i * 1ll * j) % 2019);

    cout << mn;
}