#include<iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const long long int mod1=1000000007;
const long long int mod2 = -1;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pp pop_back                                       
#define ff first
#define ss second
#define ll long long int
#define ull unsigned long long int
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered1 tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define inf mod1
ll gcd(ll a, ll b){
    ll c;
     while(b){
        c = b;
        b = a % b;
        a = c;
     }
     return a;
}
ll power1(ll a, ll b){
     if(b == 0) return 1;
     else if(b % 2) return a * power1(a, b - 1);
     else {
        ll temp = power1(a, b / 2);
        return temp * temp;
     }
}
ll power2(ll a, ll b, ll m){
     a %= m;
     if(b == 0) return 1;
     else if(b % 2) return (a * power2(a, b - 1, m)) % m;
     else{
        ll temp = power2(a, b / 2, m);
        return (temp * temp) % m;
     }
}
ll mod(ll x, ll p){
return (x % p + p) % p;
}
ll lcm(ll x, ll y){
return (x * y)/gcd(x, y);
}
int main(){
	fast;
	ll h = 1;
	//cin >> h;
    while(h--){
        ll n;
        cin >> n;
        vector<pair<string, ll> > v;
        for(int i = 0; i < n; i++){
            string x; ll y;
            cin >> x >> y;
            v.pb({x, y});
        } 
        string cur;
        cin >> cur;
        ll tot = 0;
        bool g = false;
        for(int i = 0; i < v.size(); i++){
            if(!g){
                if(v[i].ff == cur){g = true;}
            }
            else{
                tot += v[i].ss;
            }
        }
        cout << tot << endl;
}
}