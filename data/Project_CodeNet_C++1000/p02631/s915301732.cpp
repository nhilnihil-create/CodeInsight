#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define sorn(i, n) char((i == n-1)?'\n':' ')
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    ll n; cin >> n;
    ll sum = 0;
    vector<ll> a;
    rep(i, n) {
        ll tmp; cin >> tmp;
        sum ^= tmp;
        a.push_back(tmp);
    }

    int asize = a.size();
    rep(i, asize) {
        cout << (sum^a[i]) << sorn(i, asize);
    }

    return 0;
}