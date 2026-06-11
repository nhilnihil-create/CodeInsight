#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int digit(int x){
    while(x >= 10){
        x /= 10;
    }
    return x;
}
int main(){
    int N;
    cin >> N;
    ll elems[9][9];
    REP(i,9){
        REP(j,9) elems[i][j] = 0;
    }

    for(int i=1; i<10; ++i){
        for(int j=1; j <10; ++j){
            for(int k = 1; k < N+1; ++k){
                if(digit(k)==i && k % 10 == j) elems[i-1][j-1] ++;
            }
        }
    }
    ll ans = 0;
    REP(i,9){
        REP(j,9){
            if(i != j){
                ll x = elems[i][j] * elems[j][i];
                ans += x;
            }
        }
    }
    REP(i,9) ans += elems[i][i] * elems[i][i];
    cout << ans << endl;
}