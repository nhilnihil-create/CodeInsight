#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define MOD 1000000007
#define oo 1000000000000000000
#define forr(i,n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define pb push_back
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
using namespace __gnu_pbds; 
using namespace std;

ll valueOfIndex(ordered_set&s , ll i){ return *(s.find_by_order(i)); }
ll indexOfValue(ordered_set&s , ll x){ return s.order_of_key(x); }
ll add(ll a, ll b,ll p=MOD) { a%=p; b%=p; return (a+b + p)%p;}
ll mul(ll a, ll b,ll p=MOD) { a%=p; b%=p; return (a*b + p)%p;} // __int128
ll power(ll x,ll n,ll p=MOD){ if(x==0) return 0; if(n==0 || x==1) return 1LL;
    ll r = (power(x,n/2,p))%p; if(n&1) return mul(mul(r,r,p) , x,p); else return mul(r,r,p);
}
ll inv(ll x){return power(x,MOD-2);}


void __sol(){
    int n,m,x; cin >> n >> m >> x;
    int a[n+2][m+3];
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++) cin >> a[i][j];
    }
   // int mask = (1<<n);
    int ans = INT_MAX;
    forr(mask,(1<<n)){
        int temp[m+3]; memset(temp,0,sizeof(temp));
        int cost=0;
        forr(i,n){
            if( mask&(1<<i)){
                cost+= a[i][0];
                for(int j=1;j<=m;j++) temp[j]+=a[i][j];
            }
        }
        bool hit=1;
        for(int i=1;i<=m && hit;i++){
            if(temp[i]<x) hit=0;
        }
        if(hit) ans = min(ans , cost);
    }
    if(ans==INT_MAX) cout << -1;
    else cout << ans;
}


int main(){
    fastio
    ll tc=1; //cin >> tc;
    while(tc--) __sol();
    return 0;
}