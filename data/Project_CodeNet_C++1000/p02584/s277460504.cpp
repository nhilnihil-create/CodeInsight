#include <bits/stdc++.h>

using namespace std;
 
int main() {
    long long X, K, D;cin >> X >> K >> D;
    if (X<0) X=-X;
    if (X/D-K>=0){
        cout << X-K*D << endl;
    }
    else if((K-X/D)%2==0){
        cout << X%D << endl;
    }
    else {
        cout << D-X%D << endl;
    }
}