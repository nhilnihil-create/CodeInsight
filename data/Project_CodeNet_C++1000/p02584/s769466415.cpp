#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    d = abs(d);
    ll diva = min(x / d, k);
    ll mina = x - d * diva;
    if(diva == k)
        cout << mina << endl;
    else{
        ll minb = abs(mina - d);
        diva++;
        if((k - diva) % 2 == 0){
            cout << minb << endl;
        }else
            cout << mina << endl;
    }
            
}