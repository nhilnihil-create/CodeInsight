#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x, k, d;
    cin >> x >> k >> d;
    
    ll temp = abs(x);
    ll num = min(temp/d, k);
    k -= num;
    temp -= d*num;
    
    if(k%2!=0){
        cout << d-temp << endl;
    } else {
        cout << temp << endl;
    }
    
    //cout << abs(min) << endl;
    return 0;
}
