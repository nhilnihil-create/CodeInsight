#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

vector<Int> factorize(Int M){
    vector<Int> res = {};
    for(Int i=1; i*i <= M; i++){
        if(M % i == 0) {
            res.push_back(i);
            if(i*i != M) res.push_back(M/i);
        }
    }
    sort(res.begin(), res.end(), greater<Int>());
    return res;
}

int main(){
    Int N, K, sum = 0; vector<Int> A(510,0);
    cin >> N >> K;
    rep1(i,N){
        cin >> A[i];
        sum += A[i];
    }

    vector<Int> f = factorize(sum);

    rep(factor,f.size()){
        Int d = f[factor];

        vector<Int> rem(510);
        rep1(i,N) rem[i] = (A[i] % d);
        sort(rem.begin()+1, rem.begin()+1+N);

        vector<Int> sum_minus(510,0), sum_plus(510,0);
        rep1(i,N){
            sum_minus[i] = sum_minus[i-1] + rem[i];
            sum_plus[i] = sum_plus[i-1] + (d-rem[i]);
        }

        rep1(i,N){
            if(sum_minus[i] == (sum_plus[N]-sum_plus[i])){
                if(sum_minus[i] <= K){
                    cout << d << endl; return 0;
                }
            }
        }
    }
}
