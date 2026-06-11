//                        Bismillahir Rahmanir Rahim
//ALGO:
#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define FILL(a, x) memset(a, x, sizeof(a))
#define ll long long
#define _i ({int a; scanf("%d", &a); a;})
#define _l ({ll a; scanf("%lld", &a); a;})
#define _d ({double a; scanf("%lf", &a); a;})
#define _c ({char a; cin>>a; a;})
#define _s ({string a; cin>>a; a;})
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF INT_MAX
#define mx 1000010
#define mod 1000000007
#define dout if(debug) cout
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>
*/
const double Pi=acos(-1);
using namespace std;
int debug=01;
ll n, fact[10];
ll f(){
    int a[n+1];
    set<int>s;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        s.insert(i);
    }
    ll pos=1;
    for(int i=1; i<n; i++){
        pos+=distance(s.begin(), s.lower_bound(a[i]))*fact[n-i];
        s.erase(s.find(a[i]));
    }
    return pos;
}
int main() {
    Fast
    fact[0]=1;
    for(int i=1; i<9; i++) fact[i]=fact[i-1]*i;
    cin>>n;
    cout<<abs(f()-f());
}
