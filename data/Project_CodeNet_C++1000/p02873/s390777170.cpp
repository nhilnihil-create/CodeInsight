#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    string s;
    cin >> s;

    int n = s.size() + 1;

    vector<ll> v(n);

    rep(i, n - 1){
        if(s[i] == '<'){
            v[i + 1] = max(v[i + 1], v[i] + 1);
        }
    }

    rep(i, n - 1){
        if(s[n - 2 - i] == '>'){
            v[n - 2 - i] = max(v[n - 2 - i], v[n - 1 - i] + 1);
        }
    }

    ll ans = 0;

    rep(i, n){
        ans += v[i];
    }

    cout << ans << endl;


    return 0;
}
/*
Sを左からなめていき<のみチェックして
右から舐めて>をチェックする
大きいほうの値をとるようにする
*/