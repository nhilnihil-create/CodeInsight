#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
//const int MOD = 1000000007;
//const int MOD = 998244353;
const ll INF = 1001001001001;

int main(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    int sum = 0;
    rep(i,n){
        cin>>a[i];
        sum += a[i];
    }
    vi candidates;
    for(int i=1; i*i<=sum; i++){
        if(sum%i)continue;
        candidates.push_back(i);
        candidates.push_back(sum/i);
    }
    int ans = 0;
    for(int c: candidates){
        vi mod(n);
        rep(i,n){
            mod[i] = (a[i]%c);
        }
        sort(mod.begin(), mod.end());
        ll tot = 0;
        bool ok = true;
        rep(i,n){
            if(ok && tot + mod[i]<=k){
                tot += mod[i];
            }else{
                tot -= c-mod[i];
                ok = false;
            }
        }
        if(tot>=0)ans = max(ans, c);
    }
    
    cout << ans << endl;
    
    return 0;
}