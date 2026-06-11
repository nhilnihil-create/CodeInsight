#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

    #pragma GCC optimize("O3")
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    /*#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    #pragma GCC target ("avx2")*/

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

ll MAX = 1e15;
double PI = 3.141592653589793238463;
//double PI = acos(-1);
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void fac(ll x, vector<ll> &divs){
    for(ll i=2; i*i<=x; i++){
        if(x%i==0){
            divs.push_back(i);
            if(i*i!=x){
                divs.push_back(x/i);
            }
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    if(n==2){
        cout << 1;
        return;
    }
    ll m =n-1;
    vector<ll> divofn, divofm;
    set<ll> ans;
    fac(n, divofn); fac(m, divofm);
    divofm.push_back(m);
    divofn.push_back(n);
    for(auto k : divofn){
        ll cur=n;
        while(cur%k==0){
            cur/=k;
        }
        if(cur%k==1){
            ans.insert(k);
        }
    }
    for(auto k : divofm){
        ans.insert(k);
    }
    cout << ans.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }


    return 0;
}
