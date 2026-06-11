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

int main(){
    ll l,r;
    cin>>l>>r;
    ll mod=2019;
    vector<ll> v(0);
    for(ll i=l; i<=min(r,l+2*mod);i++){
        v.push_back(i%mod);
    }
    ll ans=INF;
    for(ll i=0;i<v.size()-1;i++){
        for(ll j=i+1;j<v.size();j++){
            ans=min(ans,v[i]*v[j]%mod);
        }
    }
    cout<<ans<<endl;

}