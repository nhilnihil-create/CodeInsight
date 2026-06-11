#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n>=400 && n<=599)
        cout << 8;
    if(n>=600 && n<=799)
        cout << 7;
    if(n>=800 && n<=999)
        cout << 6;
    if(n>=1000 && n<=1199)
        cout << 5;
    if(n>=1200 && n<=1399)
        cout << 4;
    if(n>=1400 && n<=1599)
        cout << 3;
    if(n>=1600 && n<=1799)
        cout << 2;
    if(n>=1800)
        cout << 1;
    cout << endl;

    return 0;
}
