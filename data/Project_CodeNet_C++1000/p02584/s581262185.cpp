#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x, k, d; cin >> x >> k >> d;
    ll cnt;
    x = abs(x);
    cnt = min(k, x/d);
    x -= d*cnt;// cout << x << "," << d-x << endl;
    if(cnt==k){
        //if(abs(x)<=d){cout << min(abs(x), abs(x-d));  return 0;}
        cout << x << endl; return 0;}
    else{
        k -= cnt;
        if(k%2==0){cout << abs(x) << endl; return 0;}
        else{cout << abs(x-d) << endl; return 0;}
    }
    return 0;
}