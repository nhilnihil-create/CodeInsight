#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, P;
string S;

int main()
{
    cin >> N >> P >> S;
    ll res = 0;
    if(P == 2 || P == 5)
    {
        for(ll i = N - 1; 0 <= i; i--)
        {
            if((S[i] - '0')%P == 0) res += i + 1;
        }
        cout << res << endl;
        return 0;
    }
    map<ll, ll> V;
    for(int i = 0; i < P; i++) V.insert(make_pair(i, 0));
    ll mp10 = 1;
    ll Ti;
    for(ll i = N; i >= 0; i--)
    {
        if(i == N)
        {
            Ti = 0;
            V[Ti]++;
        }
        else
        {
            mp10 *= N - 1 - i > 0 ? 10 : 1;
            mp10 %= P;
            Ti = mp10 * (ll)(S[i] - '0') + Ti;
            Ti %= P;
            V[Ti]++;
        }
    }
    for(int i = 0; i < P; i++)
    {
        res += V[i] * (V[i] - 1) / 2;
    }
    cout << res << endl;
    return 0;
}