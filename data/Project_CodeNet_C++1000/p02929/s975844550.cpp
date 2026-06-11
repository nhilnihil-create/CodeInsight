#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef pair <long long,long long> ii;


ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll count = 0;
    ll way = 1;
    for (int z=0;z<s.size();z++){
        ll c;
        if (s[z] == 'B') c = 1;
        else c = 0;
        if ((count + c)%2 != 0) count++;
        else {
            way *= count;
            if (way <= 0){
                cout << 0 << endl;
                return 0;
            }
            way %= mod;
            count--;
        }
        count %= mod;
    }
    if (count != 0){
        cout << 0 << endl;
        return 0;
    }
    for (int z=1;z<=n;z++){
        way *= z;
        way %= mod;
    }
    cout << max(ll(0),way%mod) << endl;
}
