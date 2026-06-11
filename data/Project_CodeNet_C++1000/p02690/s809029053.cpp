#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int x;
    cin >> x;

    for(int a=0; a*a*a*a<=x; a++){
        for(int b=0; a*a*a*a+b*b*b*b<=x; b++){
            if(a*a*a*a*a + b*b*b*b*b == x){
                if(b > a) swap(a, b);
                cout << a << " " << -b << endl;
                return 0;
            }
            else if(a*a*a*a*a - b*b*b*b*b == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}