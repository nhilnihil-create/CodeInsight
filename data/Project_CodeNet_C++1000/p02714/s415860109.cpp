#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR_IN(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int N;
    string S;
    cin >> N >> S;
    ll ans = count(S.begin(),S.end(),'R') * count(S.begin(),S.end(),'G') * count(S.begin(),S.end(),'B');
    FOR_IN(i,1,N-2){
        FOR_IN(j,i,N-1){
            int k = 2*j -i;
            if(k <= j || k > N) continue;
            if(S[i-1] != S[j-1] && S[j-1] != S[k-1] && S[i-1] != S[k-1]) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}