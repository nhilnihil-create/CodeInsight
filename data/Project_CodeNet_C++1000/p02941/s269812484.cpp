#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
#define DEBUG(x) cout << x << endl;
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n; cin >> n;
    ll a[n],b[n];
    rep(i,n) cin >> a[i];
    priority_queue<pair<ll,int>> pq;
    rep(i,n){
        cin >> b[i];
        if(a[i]!=b[i]) pq.push({b[i],i});
    }
    ll ans=0;
    while(!pq.empty()){
        pair<ll,int> p=pq.top();
        pq.pop();
        int idx=p.se;
        if(b[idx]<=b[(idx+1)%n]+b[(idx-1+n)%n]){
            cout << -1 << endl;
            return 0;
        }
        if((b[idx]-a[idx])%(b[(idx+1)%n]+b[(idx-1+n)%n])==0){
            ans+=(b[idx]-a[idx])/(b[(idx+1)%n]+b[(idx-1+n)%n]);
            b[idx]=a[idx];
            continue;
        }
        ans+=b[idx]/(b[(idx+1)%n]+b[(idx-1+n)%n]);
        b[idx]%=(b[(idx+1)%n]+b[(idx-1+n)%n]);
        if(b[idx]!=a[idx]) pq.push({b[idx],idx});
    }
    cout << ans << endl;
}
