#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

ll f(ll n){
    if(n == 0) return 1;
    ll ret = f(n / 2) * f(n / 2);
    if(n % 2 == 1) ret *= 2;
    return ret;
}

int main(){
    ll h;
    cin >> h;
    ll c = 0;
    while(h != 0){
        h /= 2;
        c++;
    }
    cout << f(c) - 1 << endl;

}