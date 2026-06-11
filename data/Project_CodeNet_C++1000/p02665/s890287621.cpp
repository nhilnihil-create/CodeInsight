#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;

    // initialize constructor
    vector<ll> leaves(N+1);
    vector<ll> notleaves(N+1);
    vector<ll> minimum(N+1);
    vector<ll> maximum(N+1);
    
    rep(i, 0, N+1) cin >> leaves[i];

    // get range (condition from leaves)
    maximum[N] = leaves.back();
    minimum[N] = leaves.back();
    rrep(i, N, 0)
    {
        maximum[i] = maximum[i+1] + leaves[i];
        minimum[i] = (minimum[i+1] + leaves[i]+1)>>1;
    }

    // pvec(maximum);
    // pvec(minimum);

    // count not leaves (condition from tree)
    ll sup = 1;
    rep(i, 0, N+1)
    {
        if (sup < minimum[i])
        {
            cout << -1 << endl;
            return 0;
        }

        ll now = min(sup, maximum[i]);
        notleaves[i] = now - leaves[i];

        sup = notleaves[i]*2;
    }
    notleaves[N] = 0;

    // count ans
    ll res =0;
    rep(i, 0, N+1)
        res += leaves[i] + notleaves[i];

    cout << res << endl;
    return 0;
}
