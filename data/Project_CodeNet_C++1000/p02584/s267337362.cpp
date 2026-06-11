#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    if(X / D >= K){
        cout << X - K * D << endl;
    }
    else
        if((K - X / D) % 2 == 1)
            cout << abs(X - (X / D + 1) * D) << endl;
        else
            cout << abs(X - (X / D) * D) << endl;
}