#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;

ll N, Q;
//値
vector<ll> value((ll)2e5,0);
//使用したかどうか
vector<bool> used((ll)2e5,false);
//連結リスト
vector<vector<ll>> G((ll)2e5);

void solve(ll n)
{
    rep(i,G.at(n).size()){
        ll nextNode =G.at(n).at(i); 
        if(used.at(nextNode))continue;
        used.at(n) = true;
        value.at(nextNode) += value.at(n);
        solve(nextNode);
        used.at(n) = false;
    }
    return;
}

int main(void)
{
    cin >> N >> Q;

    rep(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    rep(i, Q)
    {
        ll p, x;
        cin >> p >> x;
        p--;
        value.at(p) += x;
    }
    solve(0);
    rep(i,N){
        if(i>0)cout << " ";
        cout << value.at(i);
    }
    cout << endl;
}

