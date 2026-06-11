#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    bool k = true;
    for (int i = n - 1; i > 0; i--)
    {
        if (h[i - 1] - h[i] > 1)
            k = false;
        else if (h[i - 1] - h[i] == 1)
            h[i - 1]--;
    }
    rep(i, n - 1) if (h[i] > h[i + 1]) k = false;

    if (k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}