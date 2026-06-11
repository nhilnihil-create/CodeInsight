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


void solve(){
    ll n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    ll amount = (n+c)/(c+1);
    vector<ll> L, R;
    for(ll i=0; i<n; i++){
        if(s[i]=='o'){
            L.push_back(i);
            i+=c;
        }
    }
    for(ll i=n-1; i>=0; i--){
        if(s[i]=='o'){
            R.push_back(i);
            i-=c;
        }
    }
    reverse(R.begin(), R.end());
    if(L.size()>k || R.size()>k){
        return;
    }
    for(ll i=0; i<L.size(); i++){
        if(L[i]==R[i]){
            cout << L[i]+1 << "\n";
        }
    }

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
