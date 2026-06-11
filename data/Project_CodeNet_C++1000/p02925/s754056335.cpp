#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> done(N);
    int A[N+1][N+1];
    rep(i,N)rep(j,N-1){
        cin >> A[i][j];
        A[i][j]--;
    }
    bool ok = true;
    int ans = 0;
    while(ok){
        ok = false;
        vector<bool> used(N);
        for(int i=0;i<N;i++){
            if(done[i]==N-1)continue;
            int op = A[i][done[i]]; // 相手の番号
            if(used[i] || used[op])continue;
            if(A[op][done[op]] == i ){
                done[i]++;
                done[op]++;
                used[i] = true;
                used[op] = true;
                ok = true;
            }
        }
        if(ok)ans++;
    }
    rep(i,N)if(done[i]!=N-1){
        cout << -1 << endl;
        return 0;
    }    
    cout << ans << endl;
}