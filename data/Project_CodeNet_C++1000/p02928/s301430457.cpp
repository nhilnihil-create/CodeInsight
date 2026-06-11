#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<climits>
#include<string>
#include<bitset>
#include<cfloat>
#include<iomanip>
#include<numeric>

//#define int long long
#define repi(i,start,end) for(int (i)=(start),TemPNuM=(int)(end);(i)<TemPNuM;++(i))
#define rep(i,end) repi((i),0,(end))
#define rfor(x,v) for(auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fsort(v,lambda) sort(all((v)),(lambda))
#define vin(v) rep(i,(v).size())cin >> (v)[i];
#define vpin(v) rep(i,(v).size())cin>>v[i].first>>v[i].second

using namespace std;
using ll =  long long;
using pint =  pair<int,int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vpint = vector<pint>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void put_double(T a){if(cout.precision()!=12)cout<<setprecision(12);cout<<a<<endl;}
template<class T>void print(T a){cout << a << endl;}
//lambda: [](int x, int y){return x<y;}

signed main(void) {
    ll n, k; cin >> n >> k;
    vint a(n); vin(a);
    const ll mod = 1e9 + 7;
    ll ord = 0, rev = 0;
    rep(i, n) {
        rep(j, n) {
            if(i == j) continue;
            if(a[i] > a[j]) {
                ord++;
                if(i < j) rev++;
            }
        }
    }
    ll inner_ord = rev * k % mod;
    ll outer_ord = k * (k - 1) / 2 % mod * ord % mod;
    ll ans = (inner_ord + outer_ord) % mod;
    print(ans);
    return 0;
}
