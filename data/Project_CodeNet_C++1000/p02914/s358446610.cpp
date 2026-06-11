#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int mod=(int)1e9+7;
const int MAXN=(int)2e5+10;
const int INF=(int)2e9+7;
const ll LINF=(1ll<<62);
int n;ll a[MAXN];bool u[MAXN];ll all;

ll solve(ll ckr[],int n)
{
    int idx=0;
    for (int i=60; i>=0;i--)
    {
        int maxidx=idx;
        ll maxEle=-LINF;
        rep(j,idx,n)
        {
            if((ckr[j] & (1ll<<i))!=0
                     && ckr[j] > maxEle )
                maxEle = ckr[j], maxidx = j;
        }
        if (maxEle==-LINF)
        continue;
        swap(ckr[idx],ckr[maxidx]);
        maxidx = idx;
        for (int j=0;j<n;j++)
        {
            if (j != maxidx &&
               (ckr[j]&(1ll<<i))!=0)
                ckr[j] = ckr[j]^ckr[maxidx];
        }
        idx++;
    }
    ll res=0;
    for (int i = 0; i < n; i++)
        res^=ckr[i];
    return res;
}

ll f(ll x){
    return x+(all^x);
}
int main(){
    cin>>n;
    rep(i,n){
        cin>>a[i];
        all^=a[i];
    }
    sort(a,a+n);
    for(int i=60; i>=0; i--){
        rep(j,n){
            if((all>>i)%2&&(a[j]>>i)%2) {
                a[j]-=(1ll<<i);
            }
        }
    }
    ll mn=solve(a,n);
    cout<<f(mn)<<endl;
}