//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordset;
*/

#define fr first
#define sc second
#define vec vector
#define pb push_back
#define pii pair<int, int>
#define fo(x,y) for(int x = 1 ; x <= y ; ++x)
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;

typedef long long ll;
typedef unsigned int uint;
const int nmax = 200005;
const ll linf = LLONG_MAX;
const int mod = 1e9+7;
const int inf = INT_MAX;
#define pll pair<ll,ll>


ll n , range , a;
pll mon[nmax];
queue < pll > take;

int main(){
    cin >> n >> range >> a;
    range = 2*range + 1;
    fo(i,n){
        cin >> mon[i].fr >> mon[i].sc;
    }
    ll rez = 0 , delta = 0;
    sort(mon+1,mon+n+1);
    for(int m = 1 ; m <= n ;m ++){
        while(!take.empty() && take.front().fr <= mon[m].fr){
            delta += take.front().sc;
            take.pop();
        }
        while(mon[m].sc + delta > 0){
            take.push(make_pair(mon[m].fr + range, a*((mon[m].sc + delta + a - 1)/a)));
            rez += (mon[m].sc + delta + a - 1)/a;
            delta -= a*((mon[m].sc + delta + a - 1)/a);

        }
    }
    cout << rez << '\n';
}
