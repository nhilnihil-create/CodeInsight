#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    ll countZero = 0,countX = 0, countY = 0, countZ = 0;;
    ll x = -1;
    ll y = -1;
    ll z = -1;

    rep(i,n) {
        cin >> a[i];
        if(a[i] == 0) countZero ++;
        else{
            if(a[i] == x){
                countX ++;
            }else if(a[i] == y) {
                countY ++;
            }else if(a[i] == z){
                countZ ++;
            }else if(x == -1){
                x = a[i];
                countX ++;
            }else if(y == -1){
                y = a[i];
                countY ++;
            }else if(z == -1){
                z = a[i];
                countZ ++;
            }else {
                cout << "No";
                return 0;
            }
        }
    }

    if(countZero == n){
        cout << "Yes";
        return 0;
    }

    if(countZero == n/3 && countX == n/3*2){
        cout << "Yes";
        return 0;
    }

    int tmp = (x^y)^z;

    if(countX == n/3 && countY == n/3 && countZ == n/3 && (tmp == 0)){
        cout << "Yes";
        return 0;
    }


    cout << "No";


    return 0;
}
