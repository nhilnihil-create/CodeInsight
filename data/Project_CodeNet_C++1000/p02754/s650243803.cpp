#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, b, r;
    cin >> n >> b >> r;

    long long group=b+r;
    
    if (n%group<=b) {
        cout << n/group*b+n%group << endl;
    }
    else {
        cout << n/group*b+b << endl;
    }
}
        
