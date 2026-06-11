#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,flg;

    cin >> n;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    flg = 0;
    for (int i=n-1;i>0;--i) {
        if (h[i - 1] > h[i]) {
            if (--h[i-1] > h[i]) {
                ++flg;
                break;
            }
        }
    }
    if (flg==0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
