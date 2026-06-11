#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t




int main(){
    ll N; string S; cin >> N >> S;
    ll ans = 0;

    for(int num = 0; num < N; num++){
        string T = S.substr(num);
        //cout << T << endl;
        vector<ll> A(N);
        A[0] = T.size();
        int i = 1, j = 0;
        while (i < T.size()) {
            while (i+j < T.size() && T[j] == T[i+j]) ++j;
            A[i] = j;
            if (j == 0) { ++i; continue;}
            int k = 1;
            while (i+k < T.size() && k+A[k] < j) A[i+k] = A[k], ++k;
            i += k; j -= k;
        }
        for(int i1 = 1; i1 < T.size(); i1++) {
            if(A[i1] <= i1) ans = max(ans, A[i1]);
        }
    }
    cout << ans << endl;


}