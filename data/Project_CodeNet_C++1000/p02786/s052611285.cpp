#include <bits/stdc++.h>          
using namespace std;             
typedef long long ll;  

int main() {
    ll H;
    cin >> H;
    ll count = 1;
    while(H>1) {
        H /= 2;
        count++;
    }
    ll ans = pow(2,count)-1;
    cout << ans << endl;
}