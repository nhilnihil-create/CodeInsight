#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a[9];
    for (int i = 1; i <= 9; i++) cin >> a[i];
    int n;
    cin >> n;
    int b;

    rep(i, n){
        cin >> b;
        for (int j = 1; j <= 9; j++) {
            if (a[j] == b) a[j] = 0;
        }
    }
    bool okflag = false;
    if(a[1] == 0 && a[2] == 0 && a[3] == 0) okflag = true;
    if(a[4] == 0 && a[5] == 0 && a[6] == 0) okflag = true;
    if(a[7] == 0 && a[8] == 0 && a[9] == 0) okflag = true;
    if(a[1] == 0 && a[4] == 0 && a[7] == 0) okflag = true;
    if(a[2] == 0 && a[5] == 0 && a[8] == 0) okflag = true;
    if(a[3] == 0 && a[6] == 0 && a[9] == 0) okflag = true;
    if(a[1] == 0 && a[5] == 0 && a[9] == 0) okflag = true;
    if(a[3] == 0 && a[5] == 0 && a[7] == 0) okflag = true;

    if (okflag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}