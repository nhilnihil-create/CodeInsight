#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    auto k = X / D;
    if(K <= k) cout << (X - K * D) << endl;
    else{
        if((K-k)%2 == 0) cout << abs(X - k * D) << endl;
        else             cout << abs(X - (k+1) * D) << endl;
    }

    return 0;
}