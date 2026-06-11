#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    ll x; cin >> x;
    ll cnt = 0;
    ll y = 100.0;
    while(x > y){
        y += y/(100);
        cnt ++;
    }
    cout << cnt << endl;
}