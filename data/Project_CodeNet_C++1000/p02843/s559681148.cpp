#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll x;
    cin >> x;
    ll ta=x%100;
    ll judge=0;
    while(ta>=5){
        ta-=5;
        judge++;
    }
    if(ta>0) judge++;
    if(100*judge>x){
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }
}