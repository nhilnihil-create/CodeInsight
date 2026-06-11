#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n,a[105];

int main()
{
    fastio();
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) a[i] = a[i-1]+a[i];
    int ans = inf;
    rep(i,1,n-1){
        ans = min(ans,abs(a[i]-(a[n]-a[i])));
    }
    cout<<ans<<endl;
    return 0;
}
