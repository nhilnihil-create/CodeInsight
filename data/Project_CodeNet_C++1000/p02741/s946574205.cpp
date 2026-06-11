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



void solve(){
    ll arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    ll k;
    cin >> k;
    g(arr[k-1]);
}
int main()
{

 
    FASTIO
    cin.tie(NULL);
    fflush(stdout);
    ll t = 1;
   // cin >> t;
    for(ll tcase = 1;tcase <= t;tcase++){
        solve();
        
    }
return 0;
}