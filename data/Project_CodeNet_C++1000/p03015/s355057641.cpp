#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC omodtimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long ,long long> ii; 	
typedef complex<long double> com;
 
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
    cin >> s;
    vector <ll> power3(s.size()+1);
    vector <ll> power2(s.size()+1);
    power2[0] = 1;
    power3[0] = 1;
    for (int z=1;z<=s.size();z++){
        power2[z] = power2[z-1]*2;
        power3[z] = power3[z-1]*3;
        power2[z] %= mod;
        power3[z] %= mod;
    }
    ll ans = 0;
    ll c = 0;
    for (int z=0;z<s.size();z++){
        if (s[z] == '1'){
            ans += power2[c]*power3[s.size()-z-1];
            ans %= mod;
            c++;
        }
    }
    ans += power2[c];
    ans %= mod;
    cout << ans << endl;
}