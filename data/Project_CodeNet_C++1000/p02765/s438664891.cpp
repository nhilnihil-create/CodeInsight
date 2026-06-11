#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, r; cin >> n >> r;
    int diff = 100 * max(0, 10 - n);
    int ans = r + diff;
    cout << ans << endl;
}