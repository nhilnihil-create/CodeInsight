#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

ll n,k; 
ll a[200005];

bool check(ll x){
    ll cnt = 0;
    rep(i,n){
        cnt += (a[i]+x-1)/x-1;
    }
    if(cnt <= k){
        return true;
    }else{
        return false;
    }
}

int main()
{
    cin >> n >> k;
    rep(i,n) cin >> a[i];
    ll ng = 0,ok = 10000000000;
    
    while(ok - ng > 1){
        ll mid = (ok+ng)/2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
}