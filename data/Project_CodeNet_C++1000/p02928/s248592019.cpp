#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i,a,b) for (int i = a; i <= (int)(b); i++)
using namespace std;
const int MOD=1e9+7;

void add( long long &v, long long x ) {
    (v+=x)%=MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,k;
    cin >> n >> k;
    vector<int> A(n),B;
    REP(i,n) cin >> A[i];
    B=A;
    sort(B.begin(), B.end());
    long long t=0, ans=0;
    // single array inversion
    for ( int i=0; i<n; i++ ) {
        for ( int j=i+1; j<n; j++ ) {
            if ( A[i]>A[j] ) t++;
        }
    }
    add(ans, t*k%MOD);
    // count inversion of append
    t=0;
    for ( int i=0; i<n; i++ ) {
        int x = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        t+=x;
    }
    add(ans, (long long)k*(k-1)/2%MOD*t%MOD);
    cout << ans << '\n';
    return 0;
}