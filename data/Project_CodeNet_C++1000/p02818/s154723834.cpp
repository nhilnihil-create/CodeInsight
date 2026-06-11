#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    if(a + b <= k){
        cout << 0 << " " << 0 << endl;
    }
    else if(a - k < 0){
        ll p = k - a;
        b -= p;
        cout << 0 << " " << b << endl;
    }
    else{
        cout << a - k << " " << b << endl;
    }
    return 0;
}