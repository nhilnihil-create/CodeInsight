#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A[200010];

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    sort(A, A + N);
    ll ans = 0;
    if(A[0] < 0 &&  A[N - 1] < 0){
        ans = A[N - 1] - accumulate(A, A + N - 1, 0LL);
        PRINT(ans);
    }else if(A[0] > 0 && A[N - 1] > 0){
        ans = accumulate(A + 1, A + N, 0LL) - A[0];
        PRINT(ans);
    }else{ 
        REP(i, N) ans += abs(A[i]);
        PRINT(ans);
    }
    ll l = 0, r = N - 1;
    while(A[r - 1] > 0){
        cout << A[l] << " " << A[r] << endl;
        A[l] = A[l] - A[r];
        r--;
    }
    l = r - 1;
    while(l >= 0){
        cout << A[r] << " " << A[l] << endl;
        A[r] = A[r] - A[l];
        l--;
    }
    return 0;
}