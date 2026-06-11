#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll x,k,d;
    cin >> x >> k >> d;
    x = abs(x);

    if(k<x/d){
        cout << x-k*d << endl;
        return 0;
    }

    ll sp = x - (x/d)*d;
    k -= x/d;
    if(k%2==1) cout << d-sp << endl;
    else cout << sp << endl;
    return 0;

}