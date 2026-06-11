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
    int m1, d1; cin >> m1 >> d1;
    int m2, d2; cin >> m2 >> d2;

    // 2 4 6 9 11は30
    if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11){
        if(d1 == 30){
            cout << 1 << endl;
            return 0;
        }
    }else if(m1 == 2){
        if(d1 == 28){
            cout << 1 << endl;
            return 0;
        }
    }else{
        if(d1 == 31){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;



    return 0;
}
