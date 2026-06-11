#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int x, int y){
    if(y == 0) return x;
    else return f(y, x%y);
}
ll gcd(int a, int b, int c){
    return f(f(a, b), c);
}

int main(void){
    int k;
    ll ans = 0;
    cin >> k;
    for(int a = 1; a <= k; a++){
        for(int b = 1; b <= k; b++){
            for(int c = 1; c <= k; c++){
                ans += gcd(a, b, c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
