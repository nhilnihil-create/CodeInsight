// Author : Chi
// created :
// Sawal : Practice

//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <pair<int,int>, null_type, greater<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//macros
#define ll 		    long long
#define pii         pair<ll,ll>
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb(x)       push_back(x)
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define ai(a)       for(auto &i:a)cin>>i;
#define ao(a)       for(auto i:a)cout<<i<<' ';
#define TEST1       solve();
#define mod         1000000007
#define aLL(x)      x.begin(),x.end()
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define db(...)     __f(#__VA_ARGS__, __VA_ARGS__)                      //for debugging
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
//LOVE ALGO
//Make sure you have test cases (:->)
void solve(){
    int N;
    int ans=0;
    cin>>N;
    for(int i=1;i<=1000000;i++){
        for(int j=1;i*j<N && j<=1000000;j++){
            if(N-i*j>0)
                ans++;
            else
                break;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    CHI
    TEST1
    return 0;
}
