#include <bits/stdc++.h>
#define ll long long int
#define FASTIO std::ios::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define inf 1e18
#define g(x) cout<<x<<" "<<endl;
#define gg(x,y) cout<<x<<" & "<<y<<" "<<endl
#define jam(t) cout<<"Case #"<<t<<": "
#define ggg(x,y,z) cout<<x<<" & "<<y<<" & "<<z<<" "<<endl
#define all(x) x.begin(),x.end()
#define input_from_file  freopen("input.txt", "r", stdin);
#define mod 1000000007ll
#define sz 400005
#define bitcnt(x) __builtin_popcountll(x)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

ll res[sz];
 ll po (ll b, ll p) {
        return !p?1:po(b*b%mod,p/2)*(p&1?b:1)%mod;
    }
void solve(){
    ll n,k;
    cin >> n >> k;
    for(ll i=1;i<=k;i++){
        res[i] = po(k/i,n);
    }
    for(ll i=k;i>=1;i--){
        for(ll j=2*i;j<=k;j+=i){
            res[i]-=res[j];
            if(res[i] < 0)
                res[i]+=mod;
            res[i]%=mod;
        }
    }
    ll an = 0;
    for(ll i=1;i <=k;i++){
        an +=( i*res[i])%mod;
        an%=mod;
    }
    g(an);

}
int main()
{
#ifndef ONLINE_JUDGE
input_from_file
#endif
 
    FASTIO
    cin.tie(NULL);
    fflush(stdout);
    ll t = 1;
 //   cin >> t;
    for(ll tcase = 1;tcase <= t;tcase++){
        solve();
        
    }
return 0;
}