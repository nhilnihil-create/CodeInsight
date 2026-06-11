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
const int MAX=1e5+10;
const ll INF=1e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int cnt=0,ans=0;
    rep(i,n-1) {
        if (h[i+1]>h[i]) cnt=0;
        else ++cnt;
        ans=max(ans,cnt);
    }
    
    cout << ans << endl;

    return 0;   
}