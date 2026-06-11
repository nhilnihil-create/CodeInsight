#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < (ll)(r); i++)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    ll ans = 0;
    FOR(i,0,10){
        int indi = 0;
        while(indi <= N-1 && S[indi] != ('0'+i)) indi++;
        if(indi > N-3) continue;
        FOR(j,0,10){
            int indj = indi+1;
            while(indj <= N-1 && S[indj] != ('0'+j)) indj++;
            if(indj > N-2) continue;
            FOR(k,0,10){
                int indk = indj+1;
                while(indk <= N-1 && S[indk] != ('0'+k)) indk++;
                if(indk > N-1) continue;
                else ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
