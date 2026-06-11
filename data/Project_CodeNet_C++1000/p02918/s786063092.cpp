#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int K; cin >> K;
    string S; cin >> S;

    int counter = 0;
    for (int i = 1; i < N; i++){
        if(S[i] != S[i-1]){
            counter ++;
        }
    }
    int ans = N-1 - counter;
    rep(i, K){
        if(ans == N-1)break;
        ans += 2;
        if(ans == N-1){
            break;
        } else if(ans == N){
            ans--;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}