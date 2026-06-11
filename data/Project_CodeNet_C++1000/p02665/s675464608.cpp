#include<bits/stdc++.h> 
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int i = 0; i < N; i++)

int main(){
    i64 N;
    cin >> N; N++;
    vector<i64> A(N);
    vector<i64> sumA(N);
    rep(i, N) cin >> A[i];
    sumA = A;
    for(int i = N-2; i >= 0; i--) sumA[i] += sumA[i + 1];

    bool can = true;
    i64 B = 1 - A[0];
    if((A[0] > 0 && N != 1) || B < 0) can = false;

    i64 ans = B + sumA[0];
    for(int i = 1; i < N-1; i++){
        i64 b = min(2L*B - A[i], sumA[i+1]);

        if(b < 0) can = false;
        ans += b;
        B = b;
    }
    if(N != 1 && 2L*B < A[N-1]) can = false;

    if(!can) cout << -1 << endl;
    else cout << ans << endl;
}
