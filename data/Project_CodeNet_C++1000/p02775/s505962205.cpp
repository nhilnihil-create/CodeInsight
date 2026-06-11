#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    S = "00" + S;
    int n = S.length();
    int ans = 0;
    RREP(i, n - 1, 1) {
        if (S[i] > '9') {
            S[i - 1]++;
            S[i] -= 10;
        }
        if (S[i] <= '4') ans += S[i] - '0';
        else if(S[i] >= '6') {
            ans += '9' - S[i] + 1;
            S[i - 1]++;
        }else {
            if (S[i - 1] >= '5') {
                ans += 5;
                S[i - 1]++;
            } else {
                ans += 5;
            }
        }
        //cout << S << endl;
    }
    cout << ans << endl;

    return 0;
}
//     pay  receive
// 065 000  005
//     100  035   

//     pay  receive
// 055 060  005

//     pay receive
// 099 100 001 