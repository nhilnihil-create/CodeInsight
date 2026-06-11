#include<bits/stdc++.h>
using namespace std;
using lli = long long;

lli n;

int main(void){
    cin >> n;
    if(n%2 == 1) cout << 0 << endl;
    else{
        n/=2;
        lli a, b;
        a = n;
        b = 0;
        lli j = 5;
        while(j <= n){
            b+=n/j;
            j*=5;
        }
        cout << min(a, b) << endl;
    }
    return 0;
}
