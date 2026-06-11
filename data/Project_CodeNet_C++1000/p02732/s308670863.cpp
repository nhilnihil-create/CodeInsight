#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];

    map<ll,ll> mp;
    for(ll i=0;i<n;i++) mp[a[i]]++;

    map<ll,ll>::iterator it;
    ll sum = 0;
    for(it=mp.begin();it!=mp.end();it++){
        sum += it->second * (it->second - 1) / 2;
    }


    for(ll i=0;i<n;i++){
        ll cur;
        cur = mp[a[i]] - 1;
        cout << sum - cur << endl;
    }



    return 0;
}

