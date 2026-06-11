#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

vec<int> Zalgo(string S) {
    int N = S.size();
    vec<int> A(N);
    A[0]  = N;
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i + j < N && S[j] == S[i + j])
            ++j;
        A[i] = j;

        if (j == 0) {
            ++i;
        } else {
            int k = 1;
            while (i + k < N && k + A[k] < j){
                A[i + k] = A[k], ++k;
            }
            i += k, j -= k;
        }
    }
    return A;
}

int main() {
    int N;
    string S;
    cin >> N >>S;
    
    int ans = 0;
    rep(i,N){
        auto A = Zalgo(S.substr(i));
        int n = A.size();
        rep(j,n){
            if(j>=A[j]) ans = max(ans,A[j]);
        }
    }
    cout << ans << endl;
}