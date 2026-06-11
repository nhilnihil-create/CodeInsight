#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
string to_str(ll x){string res; while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return res;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end



int main(){
    int m; scanf("%d",&m);
    ll res=0,sum=0;
    rep(i,0,m){
        ll d,c; scanf("%lld%lld",&d,&c);
        sum+=d*c; res+=c;
    }
    res--; res+=(sum-1)/9;
    printf("%lld\n",res);
    return 0;
}