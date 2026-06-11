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

int S[300010];
int T[300010];
int C[300010];
map<int, int> mp;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int K = (1 << N);
    rep(i, K) cin >> S[i];
    sort(S, S + K);
    int cnt = 1;

    rep(i, K) {
        if (i > 0 && S[i] > S[i - 1]) cnt++;
        T[i] = cnt;
    }
    reverse(T, T + K);
    rep(i, K) C[T[i]]++;
    vector<int> R[20];
    R[0].push_back(T[0]);
    rep(i, N) {
        int D[300010] = {};
        sort(R[i].begin(), R[i].end(), greater<int>());
        rep(j, R[i].size()) {
            R[i + 1].push_back(R[i][j]);
            D[R[i][j]]++;
        }
        int maximam = T[0];
        rep(j, R[i].size()) {
            int less = max(1, R[i][j] - maximam);
            while (D[R[i][j] - less] + 1 > C[R[i][j] - less]) {
                less++;
                maximam = min(maximam, R[i][j] - less);
                if (R[i][j] - less <= 0) {
                    cout << "No" << endl;
                    return 0;
                }
                
            }   
            // cout << maximam << endl;
            D[R[i][j] - less]++;
            if (R[i][j] - less <= 0) {
                cout << "No" << endl;
                return 0;
            }
            R[i + 1].push_back(R[i][j] - less);
        }
        
        //rep(i, N + 1) cout << i << " " << D[i] << endl;
    }
    sort(R[N].begin(), R[N].end(), greater<int>());
    // rep(i, R[N].size()) {
    //     cout << R[N][i] << " ";
    // }
    // cout << endl;
    
    // rep(i, K) cout << T[i] << " ";
    // cout << endl;
    rep(i, R[N].size()) {
        if (R[N][i] < T[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
