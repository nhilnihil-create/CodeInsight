#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {

    int A,B,C;
    cin >> A >> B >> C;
    if(C-(A-B)<0) {
        cout << 0 << endl;
    }
    else{
        cout << C-(A-B) << endl;
    }
    return 0;
}