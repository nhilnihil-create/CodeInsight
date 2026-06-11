#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> s(m);
    vector <char> c(m);
    rep(i, m){
        cin >> s[i] >> c[i];
    }

    rep(i, powl(10, n)){
        string str = to_string(i);
        ll str_size = str.size();
        bool flg=true;
        if (str_size != n){
            continue;
        }
        rep(j, m){
            if ((s[j]-1) < str_size && str[s[j]-1] == c[j]){
                continue;
            }
            flg = false;
        }
        if (flg){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
