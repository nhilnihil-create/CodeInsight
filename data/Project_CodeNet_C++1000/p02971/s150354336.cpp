#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,ans;

    cin >> n;
    vector<int> a(n),aa(n);
    rep(i, n) {
        cin >> a[i];
        aa[i] = a[i];
    }
    sort(aa.begin(), aa.end(), greater<int>());
    rep(i, n) {
        if (a[i] == aa[0]) {
            cout << aa[1] << endl;
        }
        else {
            cout << aa[0] << endl;
        }
    }

    return 0;
}
