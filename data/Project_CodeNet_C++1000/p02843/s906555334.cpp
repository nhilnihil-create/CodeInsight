#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int x; cin >> x;

    int y = x % 100;
    int z = x / 100;

    if(y / 5 <= z){
        z -= y / 5;
        y %= 5;
    }
    if(y / 4 <= z){
        z -= y / 4;
        y %= 4;
    }
    if(y / 3 <= z){
        z -= y / 3;
        y %= 3;
    }
    if(y / 2 <= z){
        z -= y / 2;
        y %= 2;
    }
    if(y <= z){
        z -= y;
        y = 0;
    }
    if(y == 0) cout << 1 << endl;
    else cout << 0 << endl;


    return 0;
}
