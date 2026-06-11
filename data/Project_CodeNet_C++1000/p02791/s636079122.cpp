#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N, K;
    cin >> N;
    vector<ll> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    ll res = 1;
    ll mi=P[0];
    for (int i = 1; i < N; i++)
    {
        mi = min(mi, P[i]);
        if(P[i] == mi)res++;
    }
    cout<<res;
    return 0;
}