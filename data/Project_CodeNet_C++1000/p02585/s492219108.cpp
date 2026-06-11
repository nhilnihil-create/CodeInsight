#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> p(n),c(n);
    for(ll i=0;i<n;i++){
        cin>>p[i]; p[i]--;
    }
    for(ll i=0;i<n;i++) cin>>c[i];
    vector<ll> r(n), v(n);
    vector<bool> f(n,false);
    for(ll i=0;i<n;i++){
        if(f[i]) continue;
        vector<ll> visited(n,0);
        ll now=i;
        ll roop=0;
        ll value=0;
        while(true){
            now=p[now];
            if(visited[now]==0){
                roop++;
                value+=c[now];
                visited[now]++;
            }else if(visited[now]==1){
                r[now]=roop;
                v[now]=value;
                f[now]=true;
                visited[now]++;
            }else{
                break;
            }
        }
    }

    ll ans=-INF;
    for(ll i=0;i<n;i++){
        ll buf=0;
        if(k>r[i]){
            if(v[i]>0){
                ll num=k/r[i];
                num--;
                buf+=num*v[i];
            }
            ans=max(ans,buf);
            ll num=k%r[i];
            num+=r[i];
            ll now=i;
            while(num){
                now=p[now];
                buf+=c[now];
                ans=max(ans,buf);
                num--;
            }
        }else{
            ll num=k;
            ll now=i;
            while(num){
                now=p[now];
                buf+=c[now];
                ans=max(ans,buf);
                num--;
            }
        }
    }
    cout<<ans<<endl;

}