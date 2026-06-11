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
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<ll> divs(0);
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0) divs.push_back(i);
    }
    for(int i=divs.size()-1;i>=0;i--){
        if(sum==divs[i]*divs[i]) continue;
        divs.push_back(sum/divs[i]);
    }

    ll ans=0;
    for(ll div:divs){
        vector<ll> rems(0);
        for(int i=0;i<n;i++){
            ll rem=a[i]%div;
            if(rem==0) continue;
            rems.push_back(rem);
        }
        sort(rems.begin(), rems.end());
        int m=rems.size();
        vector<ll> pos(m+1,0), neg(m+1,0);
        for(int i=1;i<=m;i++){
            pos[i]=pos[i-1]+rems[i-1];
        }
        for(int i=m-1;i>=0;i--){
            neg[i]=neg[i+1]+div-rems[i];
        }
        ll num=INF;
        for(int i=0;i<=m;i++){
            if(pos[i]==neg[i]) num=pos[i];
        }
        if(num<=k) ans=max(ans,div);
    }
    cout<<ans<<endl;
}