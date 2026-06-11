#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;

    if(a < b){
        if(a + v*t >= b + w*t) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
    else{
        if(a - v*t <= b - w*t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}