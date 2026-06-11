#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll k_1,k_2;
    if(k%2 ==0){
        k_1 = ((k/2)%MOD * (k-1))%MOD;
        k_2 = ((k/2)%MOD * (k+1))%MOD;
    }else{
        k_1 = (((k-1)/2)%MOD * k)%MOD;
        k_2 = (((k+1)/2)%MOD * k)%MOD;
    }
    ll ans = 0;
    rep(i,n){
        ll cnt_1 = 0,cnt_2 = 0;
        rep(j,n){
            if(j < i && a[j] < a[i]) cnt_1 ++;
            if(j > i && a[j] < a[i]) cnt_2 ++;
        }
        ans = (ans + (cnt_1 * k_1)%MOD )%MOD;
        ans = (ans + (cnt_2 * k_2)%MOD )%MOD;
    }
    cout << ans << endl;
    return 0;  
}