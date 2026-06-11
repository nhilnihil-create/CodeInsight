#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    ll time = 0;
    vector<pair<ll,ll>> a(n);
    rep(i,n) cin >> a[i].second >> a[i].first;

    sort(a.begin(),a.end());

    for(long long i = 0; i < n; i++){
        time += a[i].second;
        if(time > a[i].first){
            put("No");
            return 0;
        }
    }
    put("Yes");
}