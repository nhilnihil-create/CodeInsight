#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;
#define F first
#define S second
#define T second.first
//#define C second.second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define OO 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll,pair<ll,ll>> piii;
const int N = 2e5+5, M= 20, mod = 1000000000;
const double EPS = 1e-10;


int main(){
    FIO
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string s, t;
    cin>>s>>t;
    int ans = 0;
    for(int i=0; i<sz(s); i++){
        if(s[i] != t[i])ans++;
    }
    cout<<ans;

}
