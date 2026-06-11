#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    ll N;
    cin >> N;
    ll P;
    cin >> P;
    string S;
    cin >> S;
    vector<ll> count(P, 0);
    ll now = 0;
    ll num = 1;
    count[0]++;
    if (P == 2){
        ll ans = 0;
        rep(i,N){
            if (ctoi(S[i]) % 2 == 0) ans += (i + 1);
        }
        cout << ans << endl;
    }
    else if (P == 5){
        ll ans = 0;
        rep(i,N){
            if (ctoi(S[i]) % 5 == 0) ans += (i + 1);
        }
        cout << ans << endl;
    }
    else{
        rep(i, N){
            now = (now + num * ctoi(S[N - i - 1])) % P;
            count[now]++;
            num = (num * 10) % P;
        }
        ll ans = 0;
        rep(i, P){
            ans += count[i] * (count[i] - 1) / 2;
        }
        cout << ans << endl;
    }
}