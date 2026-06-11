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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
map<ll,ll> mp;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        ll now; cin>>now;
        a[i]=a[i-1]+now;
        a[i]=(a[i]+k)%k;
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        a[i]-=i;
        a[i]%=k;
        a[i]=(a[i]+k)%k;
        if(i>=k) mp[a[i-k]]--;
        ans+=mp[a[i]];
        mp[a[i]]++;
        //cout<<a[i]<<":"<<ans<<endl;
    }
    cout<<ans<<endl;

}