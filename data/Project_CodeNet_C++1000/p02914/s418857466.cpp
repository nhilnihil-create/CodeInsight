#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll res = 0;
    rep(i,n)res^=a[i];
    ll ans = 0;
    ll cur = 0;
    vector<int> used(n);
    for(int j= 61;j>=0;--j){
        if(res&(1ll<<j)){
            rep(i,n){
                if(a[i]&(1ll<<j))a[i]^=1ll<<j;
            }
        }
        
        rep(i,n){
            if(used[i])continue;
            if(a[i]&(1ll<<j)){
                used[i]=1;
                rep(k,n){
                    if(i==k)continue;
                    if(a[k]&(1ll<<j))a[k]^=a[i];
                }
                break;
            }
        }
    }
    sort(a,a+n);
    reverse(a,a+n);
    if(n>65){
        n=65;
    }
    rep(_,40000){
    rep(i,n)used[i]=0;
    cur = 0;
    for(int j= 61;j>=0;--j){
        if(cur&(1ll<<j))continue;
        rep(i,n){
            if(!used[i]&&a[i]&(1ll<<j)){
                cur^=a[i];
                used[i]=1;
                break;
            }
        }
    }
    ans = max(ans,cur+(cur^res));
    random_shuffle(a, a+n);
    }
    cout<<ans<<endl;
    return 0;
}
