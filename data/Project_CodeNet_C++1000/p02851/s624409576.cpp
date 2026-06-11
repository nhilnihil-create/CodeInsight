// cpp219 - the 712534
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
using namespace std;
const ll base = 7;
const ll N = 3e5 + 9;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;

ll n,a[N],b[N],i,k;
map<ll,ll> cnt;
int main(){
    ios_base::sync_with_stdio(false);
   	cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
        b[i] = b[i - 1] + a[i];
    }
    ll ans = 0;
    //cnt[0] = 1;
    for (i=0;i<=n;i++){
        ll p = (b[i] - i)%k;
        ans += cnt[p];
        cnt[p]++;
        if (i >= k - 1){
            ll q = i - k + 1;
            ll s = (b[q] - q)%k;
            cnt[s]--;
        }
    }
    cout<<ans;
}
