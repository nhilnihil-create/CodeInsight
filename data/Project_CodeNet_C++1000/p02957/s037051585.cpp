#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {

    int A,B;
    cin >> A >> B;
    if(B >= A) {
        int C;
        C = B;
        B = A;
        A = C;
    }
    if( (A - B)%2 == 0){
        cout << (A - B)/2+B << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;


}