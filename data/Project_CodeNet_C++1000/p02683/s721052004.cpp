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
    ll n,m,x;
    cin>>n>>m>>x;
    ll ans=INF;
    vector<ll> c(n);
    vector<vector<ll> > a(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        cin>>c[i];
        for(ll j=0;j<m;j++) cin>>a[i][j];
    }

    for(ll bit=0;bit<(1<<n);bit++){
        ll cost=0;
        vector<ll> ability(m,0);
        for(ll i=0;i<n;i++){
            if(!(bit&(1<<i))) continue;
            cost+=c[i];
            for(ll j=0;j<m;j++){
                ability[j]+=a[i][j];
            }
        }
        bool f=true;
        for(ll j=0;j<m;j++){
            if(ability[j]<x) f=false;
        }
        if(f) ans=min(ans,cost);
    }
    if(ans==INF) ans=-1;
    cout<<ans<<endl;

}