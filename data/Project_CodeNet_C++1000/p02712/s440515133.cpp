#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll N,ans=0;
    cin >> N;

    for(int i = 1; i <= N; i++){
        if(i%3 == 0 || i%5 == 0) continue;
        if(i%3 == 0 && i%5 == 0) continue;
        ans += i;
    }
    cout << ans << endl;
    return 0;
}