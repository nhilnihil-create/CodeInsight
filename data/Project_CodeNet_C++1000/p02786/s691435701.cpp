#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
static const long long INF = 100000000;

ll pow(int n){
    if (n == 0){
        return 1;
    }
    else {
        ll k = 1;
        rep(i,n){
            k = 2*k + 1;
        }
        return k;
    }
}
int main(){
    ll c = 0;
    ll h;
    cin >> h;
    while (h != 1){
        h = h/2;
        c++;
    }
    cout << pow(c) << endl;
}
