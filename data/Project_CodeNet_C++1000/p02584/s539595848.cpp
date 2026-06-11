#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
 
int main() {
    ll X,K,D;
    cin >> X >> K >> D;
    X = abs(X);
    ll num = min(K,X/D);
    ll pos = X - num * D;
    
    if((num + K) % 2 == 0){
        pos = pos;
    }else{
        pos = D - pos;
    }

    cout << pos << endl;
}