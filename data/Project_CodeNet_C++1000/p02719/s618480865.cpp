#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll N, K;
    cin >> N >> K;
    ll minus = abs(N%K - K);
    ll plus = abs(N%K);
    if(minus < plus) cout << minus << endl;
    else cout << plus << endl;
    return 0;
}