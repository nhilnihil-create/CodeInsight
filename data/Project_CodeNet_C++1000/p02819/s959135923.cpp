#include <bits/stdc++.h>          
using namespace std;            
typedef long long ll;   

int main() {
    ll X;
    cin >> X;

    if (X == 2) {
        cout << 2 << endl;
        exit(0);
    }
    
    while (true) {
        
        vector<ll> num(X-2);
        for (ll j=2; j<=X-1; j++) {
            num.at(j-2) = j;
        }
        // 素数判定---------------------
        ll count = 0;
        for (ll j=0; j<X-2; j++) {
            if (X%num.at(j)==0) {
                break;
            }
            else {
                count++;
                if (count == X-2) {
                    cout << X << endl;
                    exit(0);
                }
            }
        }
        X++;
    }
    
}