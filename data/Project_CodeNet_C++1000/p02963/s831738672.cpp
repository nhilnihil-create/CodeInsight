#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    ll s; cin>>s;
    if(s==(ll)1000000000000000000){
        cout<<0<<" "<<0<<" "<<1000000000<<" "<<1<<" "<<0<<" "<<1000000000<<endl;
        return 0;
    }
    cout<<0<<" "<<0<<" "<<1000000000<<" "<<1<<" "<<1000000000 - s%(ll)(1000000000)<<" "<<s/1000000000+1<<endl;
    // cout<<(ll)311114771*1000000000-435958503<<endl;
}