#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll A,B,V,W,T;

    cin >> A >> V >> B >> W >>T;

    ll idou;
    idou = (V - W)*T;

    ll kyori;
    kyori = abs(A - B);

    if(kyori <= idou){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
