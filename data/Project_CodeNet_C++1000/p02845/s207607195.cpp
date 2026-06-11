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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(3);
    ll ans=1;
    rep(i,n) {
        int num=0,s=3;
        rep(j,3) {
            if (cnt[j]==a[i]) {
                s=(j<s)?j:s;
                ++num;
            }
        }
        ++cnt[s];
        ans=(ans*num)%MOD;
    }
    cout << ans << endl;

    return 0;
}
