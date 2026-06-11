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
const int maxn = 1e5+5;
const ll M = 1e9+7;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n,m,a[maxn];
ll f[maxn];
int main()
{
    fastio();
    cin>>n>>m;
    rep(i,1,m) {int x;cin>>x;a[x] = 1;}
    f[0] = 1;
    rep(i,1,n){
        if(a[i]) continue;
        f[i] = f[i-1];
        if(i>=2) f[i] = (f[i] + f[i-2])%M;
    }
    cout<<f[n]<<endl;
    return 0;
}
