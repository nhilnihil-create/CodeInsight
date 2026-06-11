#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int a, b, k;
    cin >> a >> b >> k;

    if(k >= a+b){
        cout << 0 << " " << 0 << endl;
    }

    else if(k >= a){
        cout << 0 << " " << b-(k-a) << endl;
    }

    else{
        cout << a-k << " " << b << endl;
    }

    return 0;
}