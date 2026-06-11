#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     ll a,b;
     cin >> a >> b;
     map<ll,ll>mp;
     ll aa = a;ll bb = b;
     for(int i = 2;i<=max(sqrt(a),sqrt(b));i++){
        if(aa%i==0){
            mp[i]++;
            while(aa%i==0) aa /= i;
        }
        if(bb%i==0){
            mp[i]++;
            while(bb%i==0) bb /= i;
        }
     }
     ll ans = 0;
     if(aa==bb&&aa!=1) ans++;
     for(auto it : mp){
        if(it.second == 2)
            ans++;
     }
     cout << ans+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}