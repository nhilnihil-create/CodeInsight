#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x; cin >> x;
    for(int i=0; i<=200; i++) {
        for(int j=-200; j<=200; j++) {
            ll num = i*i*i*i*i - j*j*j*j*j;
            if(num == x) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}