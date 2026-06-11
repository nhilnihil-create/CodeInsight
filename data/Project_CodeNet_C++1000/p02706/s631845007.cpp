#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a[10010];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i];
    int s = 0;
    for(int i = 0; i < m; i++)
        s += a[i];
    if(s > n)
        cout << "-1";
    else
        cout << n - s;

    cout << "\n";
    return 0;
}
