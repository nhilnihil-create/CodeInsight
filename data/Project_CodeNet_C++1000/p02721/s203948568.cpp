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


bool bad[sz];
ll dp[sz];
ll n,k,c;
ll get(ll x){
    // trace(x);
    if(x>n)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    if(bad[x])
        return dp[x] = get(x+1);
    ll an = 1 + get(x+c+1);
    //an = max(an,get(x+1));
    return dp[x] = an;

}
void solve(){
    
    cin >> n >> k >> c;
    string s;
    cin >> s;
    string ss = ".";
    ss+=s;
    for(ll i=1;i<=n;i++){
        if(ss[i]== 'x')
            bad[i] = true;
    }
  //  trace(bad[5]);
    for(ll i=1;i<=n;i++)
        dp[i] = -1;
    // get(1);
    for(ll i=1;i<=n;i++)
        get(i);
    ll i=1;
    vector <ll> imp;
  //  trace(dp[6]);
    ll curr = 0;
    while(i <= n){
        //trace(i);
        if(bad[i])
        {
            i++;
            continue;
        }
        if(curr + dp[i+1] >= k)
        {
            curr++;
            i+=c+1;
            continue;
        }
        else
        {
            imp.pb(i);
            curr++;
            i+=c+1;
        }
    }
    for(auto it:imp)
        g(it);

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