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
    int N, M;
    cin >> N >> M;
    string S; cin >> S;
    vector<int> v;
    while(N > 0) {
        int prev = N;
        rep(i, M) {
            if (N - M + i >= 0 && S[N - M + i] == '0') {
                v.push_back(M - i);
                N = N - M + i;
                break;
            }
        }
        if (prev == N) {cout << -1 << endl; return 0;}
    }
    rep(i, v.size()) {
        if (i != 0) cout << " ";
        cout << v[(int)v.size() - i - 1];
    }
    cout << endl;

    return 0;
}
