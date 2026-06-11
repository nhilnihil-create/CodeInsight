#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, p; cin >> n >> p;
    string s; cin >> s;

    ll ans = 0;
    if(p == 2 || p == 5){
        zep(i, 0, n){
            if((s[i]-'0')%p == 0){
                ans += i+1;
            }
        }
    }
    else{
        ll a[n];
        a[0] = 1;
        zep(i, 1, n){
            a[i] = 10*a[i-1]%p;
        }

        zep(i, 0, n){
            a[i] *= s[n-1-i]-'0';
            a[i] %= p;
        }

        zep(i, 1, n){
            a[i] += a[i-1];
            a[i] %= p;
        }

        //zep(i, 0, n){print(a[i])}

        ll cnt[p]; memset(cnt, 0, sizeof(cnt));
        rrep(i, n-1, 0){
            ans += cnt[a[i]];
            cnt[a[i]]++;
        }
        ans += cnt[0];
    }
    print(ans)
    return 0;
}