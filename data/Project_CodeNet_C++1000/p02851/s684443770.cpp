#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int N, K;
vector<Int> A(200010, 0), S(200010, 0);

Int id(Int i){
    Int res = S[i] - i;
    if(res >= 0){
        res %= K;
    } else {
        res = (K - (-res) % K) % K;
    }
    return res;
}

int main(){
    cin >> N >> K;
    rep1(i, N){
        cin >> A[i];
        S[i] = S[i-1] + A[i];
        S[i] %= K;
    }

    map<Int,Int> M;

    Int ans = 0;
    rep1(j,N){
        Int R = j-1, L = j-K;
        M[id(R)]++;
        if(L >= 0){
            M[id(L)]--;
        }

        ans += M[id(j)];
    }

    cout << ans << endl;




}