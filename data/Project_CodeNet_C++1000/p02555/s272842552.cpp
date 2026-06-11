#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll S[2007];
int main()
{
    ll N;
    cin >> N;
    if(N<=2) cout << 0 << endl;
    else {
        ll ans  = 0;
        S[0] = 1;S[1] = 1;S[2] = 1;
        for(ll i=3;i<=N;i++)
        {
            S[i] = S[i-1]+S[i-3];
            S[i] %= MOD;
        } cout << S[N-3] << endl;
    }
}
