//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 998244353;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

//a^n (mod)
in modpow(in a, in n, in mod) {
    in res = 1ll;
    while (n > 0ll) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n;
    cin>>n;
    vector<in> a(n-1,0);
    in a1;
    cin>>a1;
    if(a1!=0ll){
        cout<<0<<endl;
        return 0;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    rep(i,n-1) cin>>a.at(i);
    sort(all(a));
    if(a[0]==0){
        cout<<0<<endl;
        return 0;
    }
    in cnt=upper_bound(all(a),1)-a.begin();
    in now=1ll;
    in ans=1ll;
    while(now!=a[a.size()-1ll]){
        now ++;
        in cnt2=upper_bound(all(a),now)-upper_bound(all(a),now-1);
        ans *=modpow(cnt,cnt2,MOD);
        ans %=MOD;
        cnt =cnt2;
    }
    cout<<ans<<endl;
}