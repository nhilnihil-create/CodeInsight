#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T>ostream &operator<<(ostream &o,const pair<T, T>&p)
{o<<"("<<p.first<<", "<<p.second<<")";return o;}

#define rep(i, n) for(lli i = 0; i < (lli)(n); i++)

const lli MOD = 1000000007LL;

lli modpow(lli a, lli n){
    lli res = 1;

    for(lli ai = a; n; n>>=1){
        if(1&n) res = (res*ai)%MOD;
        ai=(ai*ai)%MOD;
    }
    return res;
}

lli inv(lli n){
    return modpow(n, MOD-2);
}

lli modperm(lli n, lli k){
    lli res = 1;
    rep(i, k){
        res = (res*(n-i))%MOD;
    }
    return res;
}

lli modcomb(lli n, lli k){
    return (modperm(n, k)*inv(modperm(k, k)))%MOD;
}

lli posmod(lli n){
    lli res = n;
    res %= MOD;
    if(res < 0) res += MOD;
    return res;
}
#define MAX_N 100100
int n;
vector<pair<int, int>> p;
int x, l;

int main(void){
    cin >> n;
    rep(i, n){
        pair<int, int> pi;
        cin >> x >> l;
        pi.first = x-l;
        pi.second = x+l;
        p.push_back(pi);
    }
    sort(p.begin(), p.end(), [](auto const& a, auto const& b){
        if(a.second <= b.second) return true;
        else return false;
    });
    int res = 0;
    int t = -INT_MAX;
    rep(i, n){
        if(t <= p[i].first){
            t = p[i].second;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
