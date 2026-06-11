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
    int a, b, m; cin >> a >> b >> m;
    vint va(a); vin(va);
    vint vb(b); vin(vb);
    vector<pint> xy(m);
    vint c(m);
    rep(i, m) {
        int x, y; cin >> x >> y >> c[i];
        xy[i].first = x - 1;
        xy[i].second = y - 1;
    }
    int ans = *min_element(all(va)) + *min_element(all(vb));
    rep(i, m) {
        int x = xy[i].first, y = xy[i].second;
        chmin(ans, va[x] + vb[y] - c[i]);
    }
    print(ans);

    return 0;
}
