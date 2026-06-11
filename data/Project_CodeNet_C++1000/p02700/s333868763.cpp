#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while(1){
        c -= b;
        if(c <= 0){
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if(a <= 0){
            cout << "No" << endl;
            return 0;
        }
    }

    return 0;
}