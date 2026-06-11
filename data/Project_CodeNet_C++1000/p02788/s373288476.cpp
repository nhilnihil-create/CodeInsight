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
    ll n,d,a;
    cin>>n>>d>>a;
    vector<P> p(n);
    for(ll i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    sort(p.begin(),p.end());
    vector<ll> x(n),h(n);
    for(ll i=0;i<n;i++){
        x[i]=p[i].first;
        h[i]=p[i].second;
    }
    ll ans=0;
    vector<ll> damage(n+1,0);
    for(ll i=0;i<n;i++){
        ll now=x[i];
        ll hp=h[i];
        damage[i+1]+=damage[i];
        ll num=(hp-damage[i+1]+a-1)/a;
        num=max(num,(ll)0);
        ans+=num;
        damage[i+1]+=num*a;
        ll next=upper_bound(x.begin(),x.end(),now+2*d)-x.begin();
        if(next>=n) continue;
        next++;
        damage[next]-=num*a;
    }
    cout<<ans<<endl;
}