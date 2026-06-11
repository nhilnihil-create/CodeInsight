#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e12
const int MOD = 1000000007;
typedef pair<ll,ll> P;

int main(void){
    ll K,N,mP=-INF,ans=0;
    cin >> K >> N;
    vector<ll> A(N+10,0);
    vector<ll> Pass(N+10);
    REP(i,N){
        cin >> A[i];        
    }
    REP(i,N-1){
        Pass[i] = abs(A[i+1] - A[i]);
        ans += Pass[i];
        mP = max(mP,Pass[i]);
    }
    Pass[N-1] = abs(A[0]+(K-A[N-1]));
    ans += Pass[N-1];
    mP = max(mP,Pass[N-1]);

    cout << ans - mP << endl;
    return 0;
}