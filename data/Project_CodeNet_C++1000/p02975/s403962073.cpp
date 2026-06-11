#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){
    int N; cin >> N;

    vector<Int> A(N);
    rep(i,N) cin >> A[i];

    Int all_xor = A[0];
    rep1(i,N-1) all_xor ^= A[i];

    if(all_xor != 0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }


    
}
