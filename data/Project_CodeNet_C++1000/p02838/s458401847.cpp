#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;


int main() {
    ios_base::sync_with_stdio(false); 

    ll n;
    cin >> n;
    vector<ll> cnt(65);
    rep(i,n) {
        ll a;
        cin >> a;
        ll ele=1;
        int c=0;
        while (a>0) {
            ele*=2;
            if (a%ele>0) ++cnt[c];
            a=a-a%ele;
            ++c;
        }
    }
    ll ele=1,ans=0;
    rep(i,62) {
        ans+=(ele*(cnt[i]*(n-cnt[i])%MOD)%MOD)%MOD;
        ans=ans%MOD;
        ele=(ele*2)%MOD;
    }
    cout << ans << endl;

    return 0;
}
