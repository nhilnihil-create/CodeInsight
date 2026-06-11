#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x;
    cin >> x;

    for (ll a = -200; a < 200; a++){
        bool r = false;
        for (ll b = -200; b < 200; b++){
            if (a*a*a*a*a - b*b*b*b*b == x){
                cout << a << " " << b << endl;
                r = true;
                break;
            }
            
        }
        if (r){
            break;
        }
    }


}