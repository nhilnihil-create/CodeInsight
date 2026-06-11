#include <bits/stdc++.h>
#define rep(i, n) for (Int i = 0; i < (Int)(n); i++)
typedef int64_t Int;
using namespace std;
 
int main(){
    int M; cin >> M;
    Int D = 0, S = 0;
    rep(i, M){
        Int d, c; cin >> d >> c;
        D += c; S += d*c;
    }

    cout << (D-1) + (S-1)/9 << endl;
}