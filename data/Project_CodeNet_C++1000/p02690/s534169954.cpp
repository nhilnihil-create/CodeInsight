#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll pow5(ll x){
    return x*x*x*x*x;
}


int main(){
    ll x;
    cin >> x;
    for(int a = -200; a <= 200; a++){
        for(int b = -200; b < a; b++){
            if(pow5(a) - pow5(b) == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}
