#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    if(a - k < 0){
        ll x = abs(a - k);
        a = 0;        
        if(b - x < 0){
            b = 0;
        }else{
            b -= x;
        }
        
    }else{
        a -= k;
    }
    
    cout << a << " " << b << endl;
    return 0;
}