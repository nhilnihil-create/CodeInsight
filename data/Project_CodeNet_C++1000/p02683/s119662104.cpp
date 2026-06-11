/*
    書籍を買うor買わないについてのbit全探索 O(N*M*2^N)
    もしくは深さ優先探索
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main (void){
    int N,M;
    ll X;
    cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll>> A(N,vector<ll>(M));
    rep(i,N){
        cin >> C[i];
        rep(j,M){
            cin >> A[i][j];
        }
    }
    ll ans = 99999999;
    for(int bit=0; bit < (1 << N); ++bit){
        vector<ll> levels(M);
        ll cost = 0;
        rep(i,N){
            if(bit & (1 << i)){
                cost += C[i];
                rep(j,M){
                    levels[j] += A[i][j];
                }
            }
        }
        bool can_buy = true;
        rep(i,M){
            if(levels[i] < X){
                can_buy = false;
            }
        }
        if(can_buy){
            ans = min(ans,cost);
        }
    }
    
    if(ans == 99999999) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}