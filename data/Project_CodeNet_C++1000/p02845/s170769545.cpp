#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MOD = 1000000007;
const ll MAXN = 200000;

ll N, ans=1, tmp=0;
vector<ll> A(MAXN, 0), M(MAXN, 3);

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) {
        if(!A[i]) {
            ans *= M[A[i]];
            M[A[i]]--;
        }
        else {
            ans *= M[A[i]] - M[A[i]-1];
            ans %= MOD;
            M[A[i]]--;
        }
    }
    cout << ans << endl;
    return 0;
}