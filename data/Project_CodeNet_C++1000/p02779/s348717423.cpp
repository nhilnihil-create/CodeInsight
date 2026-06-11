#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    set<ll> a;
    ll tmp;
    rep(i,n) {
        cin >> tmp;
        a.insert(tmp);
    } 

    if(a.size() == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}