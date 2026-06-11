#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll a,ll b){
    ll big,small;
    if(a > b){
        big = a;
        small = b;
    }else{
        big = b;
        small = a;
    }
    ll tmp_small;
    while(true){
     tmp_small = small;
        small = big % small;
        if(small == 0) break;
        big = tmp_small;
    }

    return a * b / tmp_small;
}

ll number(ll s,ll g,ll r){
    ll first,last;
    if(s % r == 0){
        first = s / r;
    }else{
        first = s / r + 1;
    }

    last = g / r;
    return last - first + 1;
}

int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll all = b - a + 1;
    ll l = lcm(c,d);
    ll num = all - number(a,b,c) - number(a,b,d) + number(a,b,l);
    cout << num << endl;
}