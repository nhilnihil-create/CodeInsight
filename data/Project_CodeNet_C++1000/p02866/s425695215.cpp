#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i))
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(x,v) for(const auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義 #define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//lambda: [&](int x, int y){return x<y;}

const int MOD = 998244353;

signed main(void){
    int n;cin>>n;
    int dmax=0;
    vint cnt(n,0);
    rep(i,n){
        int d;cin>>d;
        if(i==0&&d!=0||i!=0&&d==0){
            cout << 0 << endl;
            return 0;
        }
        cnt[d]++;
        chmax(dmax,d);
    }

    ll ans=1;
    rep(i,dmax){
        ll res=1;
        rep(j,cnt[i+1])res=res*cnt[i]%MOD;
        ans=ans*res%MOD;
    }
    cout << ans << endl;

    return 0;
}
