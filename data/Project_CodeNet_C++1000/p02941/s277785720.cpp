#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
// #define exit(a, b) return cout << a, b;

#define loop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end() 

#define print(stuff) cout << stuff << endl
#define printc(stuff) for(auto x: stuff) cout << x << " "; cout << endl;
#define printPrec(stuff) cout << fixed << setprecision(15) << stuff << endl;
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;
#define len length
#define ret0 return 0
#define ret return 

#define ll long long
#define ld long double
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fill(ar, x) memset(ar, x, sizeof ar)

#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>

// typedef tree<ll,null_type,less<ll>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;

#define inf (long long int) 1e18
#define eps 0.000001
#define mod 1000000007
#define mod1 998244353
#define MAXN (ll)1e5+5


// ll f2(ll n){
//     // for(int i=0; i<n; i++){
//     //     cout<<b[i]<<" ";
//     // }
//     // cout<<endl;
//     while(!q.empty() && b[q.top().se] == a[q.top().se]){
//         // debug(q.top().se);
//         // debug(b[q.top().se]);
//         // debug(a[q.top().se]);
//         q.pop();
//     }
//     if(q.empty()){
//         return 0;
//     }
//     if(b[q.top().se] < a[q.top().se]){
//         return -1;
//     }
//     else {
//         ll x = q.top().se;
//         ll y = b[(x-1+n)%n] + b[(x+1+n)%n];
//         if(b[x] <= y){
//             return -1;
//         }
//         else {
//             ll tim = (b[x]-a[x])/y;
//             ans2+=tim;
//             b[x]-=tim*y;
//             q.pop();
//             q.push(mp(b[x],x));
//             return f2(n);
//         }
//     }
// }

void solve(){
    ll n;
    cin>>n;
    ll a[n], b[n];
    priority_queue<pll> q;
    loop(i,0,n){
        cin>>a[i];
        // q1.push(mp(a[i], i));
    }
    loop(i,0,n){
        cin>>b[i];
        q.push(mp(b[i], i));
    }
    
    ll ans = 0;
    while(!q.empty()){
        if(a[q.top().se] > b[q.top().se]){
            print(-1); ret;
        }
        while(!q.empty() && b[q.top().se] == a[q.top().se]){
            q.pop();
        }
        if(q.empty()){
            break;
        }
        if(a[q.top().se] > b[q.top().se]){
            print(-1); ret;
        }
        else {
            ll x = q.top().se;
            ll y = b[(x-1+n)%n] + b[(x+1+n)%n];
            // debug(x);
            // debug(y);
            if(b[x] <= y){
                print(-1);
                ret;
            }
            ll tim = (b[x]-a[x])/y;
            if(tim <= 0){
                print(-1);
                ret;
            }
            ans+=tim;
            // debug(tim);
            q.pop();
            b[x]-=tim*y;
            q.push(mp(b[x],x));
        }

    }

    print(ans);
    
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    
        
   
}

