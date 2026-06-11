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
    ll n,k; cin >> n >> k;
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> visit(n+2,0) , v,p;
 //   visit[1]=1;
   // v.eb(1);
    int start = a[1];
 //   cout << start << " ";

    while(1){
        if(!visit[start]){
        v.eb(start);
        visit[start] = 1;
        start = a[start];
        }
        else{
            if(start==a[1]){
                break;
            }
            else{
                int tt = start;
                p.eb(tt);
                tt = a[tt];
                while(tt!=start){
                    p.eb(tt);
                    tt = a[tt];
                }
                break;

            }
        }
    }
 //   for(auto &i: v) cout << i << " ";
    if(p.size()==0){
    if(k<=v.size()){
        cout << v[k-1];
    }
    else{
        ll sz = v.size();
        if(k%sz==0){
            cout << v[sz-1];
            return;
        }
        k = k%sz;
      //  cout << k << "**\n";
        k = (k-1+sz)%sz;
        cout << v[k];
    }
    }
    else{
        int tt = v.size() - p.size();
        if(k<=tt){
            cout << v[k-1];
        }
        else{
            k-=tt;
            tt = p.size();
            k = k%tt;
            k = (k-1+tt)%tt;
            cout << p[k];
        }
    }
}


int main(){
    fastio
    ll tc=1; //cin >> tc;
    while(tc--) __sol();
    return 0;
}