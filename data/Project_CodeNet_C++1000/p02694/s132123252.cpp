#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll m = 100;
    ll x, ans = 0;
    cin >> x;
    
    while(m < x){
        m += m/100;
        ans ++;
    }
    
    cout << ans;    
}