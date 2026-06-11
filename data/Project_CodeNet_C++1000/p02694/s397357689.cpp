#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll ans=0,money=100,X;
    cin >> X;
    while(X > money){
        ans++;
        money += money/100;
    }
    cout << ans << endl;
    return 0;
}