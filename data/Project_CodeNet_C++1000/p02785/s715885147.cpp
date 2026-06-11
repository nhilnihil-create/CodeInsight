#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    sort(H.rbegin(), H.rend());
    ll res = 0;
    for (int i = K; i < N; i++)
    {
        res += H[i];
    }
    cout << res;
    return 0;
}