#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    ll ans = 0;
    rep(i, 0, N){
        if(i + K < N && T[i + K] == T[i]){
            T[i + K] = 'd';
        }
        {
            if(T[i] == 's') ans += R;
            if(T[i] == 'r') ans += P;
            if(T[i] == 'p') ans += S;
        }
    }
    cout << ans << endl;
    return 0;
}