#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)
 
 
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
int main(){
    ll n,k,ans=0;
    cin >> n >> k;
    vector<ll> H(n,0);
    rep(i,n){
        cin >> H[i];
    }
    sort(H.begin(),H.end());

    for(int i=0;i<n-k;i++){
        ans+=H[i];
    }
    cout << ans << endl;
    return 0;
}