#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

// A,Bの範囲を考える．この時，Xが正の整数であるから，単調増加する数列のうち，最も増分が低いものを考える．
// y = (x+1)^5 - x^5の数列を考える．
//この時，およそx ~ 200 でyはXの範囲を超えてくるのでこれをA,Bの範囲とする．
int main (void){
    ll X;
    cin >> X;
    int A,B;
    FOR(i,-200,200){
        FOR(j,-200,200){
            if(pow(i,5) - pow(j,5) == X){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}