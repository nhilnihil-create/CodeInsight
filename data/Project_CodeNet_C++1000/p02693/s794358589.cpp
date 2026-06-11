#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K, a, b;
    cin >> K >> a >> b;
    int lb = b % K;
    if ((b - lb) >= a)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NG" << endl;
    }
    return 0;
}
