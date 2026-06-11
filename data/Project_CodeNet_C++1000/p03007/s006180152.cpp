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
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    sort(A, A + N);
    int ans = 0;
    vector<pair<int, int>> v;
    int sum = A[0];
    rep(i, N - 2) {
        //cout << sum << " " << A[N - i - 2] << endl;
        if (A[N - i - 2] <= 0) {
            v.push_back({A[N - 1], A[N - i - 2]});
            A[N - 1] -= A[N - i - 2];
        } else {
            v.push_back({sum, A[N - i - 2]});
            sum -= A[N - i - 2];
        }
    }
    ans = A[N - 1] - sum;
    v.push_back({A[N - 1], sum});
    
    
    cout << ans << endl;
    rep(i, N - 1) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
