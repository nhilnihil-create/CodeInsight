#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    int r = n%10;
    if(r == 3) cout << "bon" << endl;
    else if(r == 0 || r == 1 || r == 6 || r == 8) cout << "pon" << endl;
    else cout << "hon" << endl;

    return 0;
}