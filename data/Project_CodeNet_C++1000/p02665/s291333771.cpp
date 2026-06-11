#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 2e5 + 9;
const ll inf = 1e8;
typedef pair<ll,ll> LL;

ll n,a[N],i,fr[N],b[N],ans;
ll bpow(ll a,ll b){
    if (b == 0) return 1;
    ll t = bpow(a,b/2);
    if (b%2 == 0) return t*t;
    return t*t*a;
}
ll min3(ll x,ll y,ll z){
    return min(x,min(y,z));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n; n++;
    for (i = 1;i <= n;i++){
        cin>>a[i]; b[i] = b[i - 1] + a[i];
    }
    if (n == 1){
        if (a[1] == 1) cout<<1;
        else cout<<-1;
        return 0;
    }
    fr[1] = 1 - a[1];
    for (i = 2;i <= n;i++){
        if (i < 45) fr[i] = min3(fr[i - 1]*2 - a[i],b[n] - b[i],bpow(2,i - 1) - a[i]);
        else fr[i] = min(fr[i - 1]*2 - a[i],b[n] - b[i]);
        if (fr[i] < 0){
            cout<<-1; return 0;
        }
        ans += fr[i] + a[i];
    }
    ans++;
    cout<<ans;
}
