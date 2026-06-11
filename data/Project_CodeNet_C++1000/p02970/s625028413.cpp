#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, D;
    cin >> N >> D;
    int i = 0;
    int ans = 0;
    while(i < N)
    {
        i+=D;
        ans++;
        i+=D+1;
    }
    cout << ans << endl;

    return 0;
}
