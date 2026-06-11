#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll l,r;
    cin >> l >> r;
    if (r-l>=2019 || l%2019>r%2019) cout << 0 << endl;
    else {
        int ans=2018;
        int ll=l%2019,rr=r%2019;
        repr(i,ll,rr+1) {
            repr(j,i+1,rr+1) ans=min(ans,(i*j)%2019);
        }
        cout << ans << endl;
    }

    
    
    return 0;  
}