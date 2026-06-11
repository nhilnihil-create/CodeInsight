#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    ll A, B;
    for (ll i=-200; i<=200; i++) {
        for (ll j=-200; j<=200; j++) {
            if (pow(i,5)-pow(j,5)==X) {
                A = i;
                B = j;
                break;
            }
        }
    }
    cout << A << ' ' << B << endl;
}