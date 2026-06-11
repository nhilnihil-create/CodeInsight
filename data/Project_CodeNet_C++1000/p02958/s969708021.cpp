#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    rep(i, n)
    {
        int k;
        cin >> k;
        if (i + 1 != k)
            cnt++;
    }
    if (cnt < 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}