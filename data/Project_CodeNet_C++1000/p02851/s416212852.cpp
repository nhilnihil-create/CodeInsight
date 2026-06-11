#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;



int main(){FIN

    ll n,k;cin>>n>>k;
    vll a(n, 0);
    REP(i,n) cin>>a[i];
    vll rui(n+1,0);
    ll sum=0;
    map<ll,ll> mp;
    REP(i,n){
        sum+=a[i];
        rui[i+1] = sum-i-1;
        rui[i+1] %= k;
    }
    sum=0;
    for(auto p:mp){
        sum += p.second * (p.second-1) /2;
    }
    REP(i,min(k-1, n)){
        mp[rui[i+1]]++;
    }
    sum =0;
    for(ll i=0; i<n; i++){
        sum+=mp[rui[i]];
        mp[rui[i+1]]--;
        if (i+k-1<n) mp[rui[i+k]]++;
    }
    cout<<sum<<endl;
    return 0;
}