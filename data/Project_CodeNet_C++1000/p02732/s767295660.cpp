#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

bool in(vll l, ll p){
    rep(i, l.size()) if(l[i]==p) return true;
    return false;
}

ll calc(ll n){
    return n*(n-1)/2;
}

int main(){

    ll n; cin >> n;
    vll a(n);
    vll cnt(n, 0);
    rep(i, n){
        cin >> a[i];
        cnt[a[i]-1]++;
    }

    ll sum = 0;
    rep(i, n) sum += calc(cnt[i]);

    rep(i, n) cout << sum-(cnt[a[i]-1]-1) << endl;

    return 0;
}