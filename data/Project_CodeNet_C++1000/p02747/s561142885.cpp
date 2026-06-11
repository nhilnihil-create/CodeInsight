#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define loop(i, a, b) for(lli i=a; i<b; i++)
#define loopb(i, a, b) for(lli i=a; i>=b; i--)
#define pb push_back
#define umap unordered_map
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vll;
typedef pair<lli, pii> ppi;
typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// use to avoid collision
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// for pair in unordered_map
struct hash_pair {
    static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
    }
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        uint64_t x = hash1 ^ hash2;
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
lli M = 1e9 + 7;
lli power(lli x, lli y){
    lli res = 1;
    x = x%M ;
    while (y > 0) {
        if (y & 1)
            res = (res*x)%M ;
        y = y>>1;
        x = (x*x)%M;
    }
    return res%M;
}
lli solve(){
    string s;
    cin>>s;
    lli n = s.length();
    s += "....";
    lli i = 0;
    while(i < n){
        string temp = s.substr(i, 2);
        if(temp == "hi")
            i += 2;
        else{
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}
int main(){
    fastio;
    lli t;
    // cin>>t;
    t = 1;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}