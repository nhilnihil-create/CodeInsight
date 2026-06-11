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

#define int long long
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


bool judge(ll n, ll k) {
    if(n % k == 0) while(n % k == 0) n /= k;
    return n % k == 1;
}

signed main(void) {
    ll n; cin >> n;
    ll ans = -1;
    
    for(int i = 1; i * i <= n - 1; ++i) {
        if((n - 1) % i == 0) {
            ans++;
            if((n - 1) / i != i) ans++;
        }
    }

    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ll d = n / i;
            if(i != 1 && judge(n, i)) ans++;
            if(d != i && judge(n, d)) ans++;
        }
    }
    print(ans);
    return 0;
}
