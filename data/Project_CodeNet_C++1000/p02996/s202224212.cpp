#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> ps;
    rep(i, N){
        cin >> A[i] >> B[i];
        ps.push_back(make_pair(B[i], A[i]));
    }
    sort(ps.begin(), ps.end());

    ll sum = 0;
    rep(i, N){
        sum += ps[i].second;
        if (sum > ps[i].first){
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    

    return 0;
}
