#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ll H;
    cin >> H;
    ll n = 1;
    while(true) {
        if(H != 1) {
            H /= 2;
            n ++;
        } else {
            break;
        }
    }
    cout << (ll)(pow((ll)2,(ll)n) - (ll)1) << endl;


    return 0;
}