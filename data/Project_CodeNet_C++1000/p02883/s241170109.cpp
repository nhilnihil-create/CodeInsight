#include <bits/stdc++.h>
using namespace std;

int64_t N,K;
vector<int64_t> A,F;

// costをx以下にすることができるか
bool isOK (int64_t x ){
    int64_t K0 = 0;
    for ( int i = 0; i < N; ++i){
        int64_t cost = A[i] * F[i];
        //cout << "cost " << cost << " x " << x << endl;
        if ( cost > x ){
            K0 = K0 + ( cost - x ) / F[i];
            if ( ( cost - x ) % F[i] ) ++K0;
        }
    }
    //cout << K0 << " " << K << endl;
    if ( K0 <= K ) return true;
    else return false;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    F.resize(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A[i];
    }
    for ( int64_t i = 0; i < N; ++i){
        cin >> F[i];
    }
    
    sort(A.begin(),A.end());
    sort(F.begin(),F.end(),greater<int64_t>());
    
    int64_t ok = 1e+12 + 1, ng = -1;
    int64_t mid;
    while ( ok - ng > 1 ){
        mid = ( ng + ok ) / 2;
        //cout << mid << endl;
        if ( isOK(mid) ){
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    cout << ok << endl;
    
    return 0;
}
