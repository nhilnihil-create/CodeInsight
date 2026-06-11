#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int s, w;
    cin >> s >> w;

    if(w >= s) cout << "unsafe" << endl;
    else cout << "safe" << endl;

    return 0;
}