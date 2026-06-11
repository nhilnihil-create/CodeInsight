#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int x, n;
    cin >> x >> n;

    vector<bool> q(101, false);
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        q[p] = true;
    }

    for(int i=0; i<=x; i++){
        if(x-i < 0 || q[x-i] == false){
            cout << x-i << endl;
            return 0;
        }
        if(x+i > 100 || q[x+i] == false){
            cout << x+i << endl;
            return 0;
        }
    }


    return 0;
}