#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> P(N, 0);
    vector<ll> Q(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        --P[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i];
        --Q[i];
    }

    map<vector<ll>, ll> ord;
    vector<ll> seq(N);

    ll iter = 0;
    for (ll i = 0; i < N; i++)seq[i] = i;

    do{
        ord[seq] = iter++;
    }while(next_permutation(seq.begin(),seq.end()));

    cout << abs(ord[P] - ord[Q]);
    return 0;
}