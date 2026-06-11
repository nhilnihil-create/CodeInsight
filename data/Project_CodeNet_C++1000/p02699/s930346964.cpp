#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int S,W;
    cin >> S >> W;
    if(W >= S) cout << "unsafe" << endl;
    else cout << "safe" << endl;
    return 0;
}