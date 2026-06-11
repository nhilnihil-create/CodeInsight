#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N,K;
    string S;
    cin >> N >> K >> S;

    ll ans = 0;
    ll cnt_LR = 0;
    for(int i = 0; i < N - 1; i++){
        if(S[i] != S[i + 1]){
            cnt_LR++;
        }
    }

    ans = N - 1 - max(cnt_LR - 2 * K, ll(0));

    cout << ans << endl;

}
