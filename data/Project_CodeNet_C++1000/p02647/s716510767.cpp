#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int N,K; cin >> N >> K;
    vi A(N);
    rep(i,N) cin >> A[i];

    rep(i,K){
        bool flag = true;
        vi B(N, 0);
        rep(j,N){
            if(flag && A[j] < N) flag = false;
            B[max(0,(int)j-A[j])]++;
            if((int)j+A[j] < N-1) B[(int)j+A[j]+1]--;
        }

        rep(j,N-1) B[j+1] += B[j]; 
        rep(j,N) A[j] = B[j];
        if(flag) break;
    }
    
    rep(i,N) {
        cout << A[i] << "\n";
    }
    return 0;
}
