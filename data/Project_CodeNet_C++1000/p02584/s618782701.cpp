#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x, k, d;
    long double y;
    cin >> x >> k >> d;
    y = (long double) abs(x) / (long double) d;
    if(y > k){
        cout << abs(abs(x) - k * d);
    }
    else if(y == k || ((long long)y == y && (k - (long long)y) % 2 == 0)){
        cout << 0;
    }
    else{
        if((k - (long long)y) % 2 == 0){
            cout << abs(abs(x) - (long long)y * d);
        }
        else{
            cout << abs(abs(x) - ((long long)y + 1) * d);
        }
    }
}