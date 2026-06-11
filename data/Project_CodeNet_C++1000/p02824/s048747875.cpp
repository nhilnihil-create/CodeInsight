#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

ll N, M, V, P;
ll A[100000], S[100001];

signed main(){
    cin >> N >> M >> V >> P;
    rep(i, N) cin >> A[i];
    sort(A, A+N);
    rep(i, N) S[i+1] = S[i] + A[i];

    ll ans = 0;
    rep(i, N){
        if(i >= N-P){
            ans++;
            continue;
        }
        if(A[i]+M < A[N-P]){
            continue;
        }
        ll v = V - 1 - i - (P-1);
        if(v <= 0){
            ans++;
            continue;
        }
        if((A[i]+M)*(N-P-i) - (S[N-P+1]-S[i+1]) >= v*M){
            ans++;
        }
    }
    cout << ans << endl;
}