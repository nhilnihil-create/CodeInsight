#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
const int MOD = 1000000007;
int main(void){
    int N,K;
    ll sum = 0;
    cin >> N >> K;
    for(ll i=K;i <= N+1;i++){
        ll mini = i*(i-1)/2;
        ll maxi = (2*N-i+1)* i / 2;
        ll res = maxi - mini + 1;
        sum = (sum+res)%MOD;
    }
    cout << sum << endl;
    return 0;
}