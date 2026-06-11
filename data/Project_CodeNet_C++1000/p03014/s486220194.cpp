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

int n,m,lft[2005][2005],rgt[2005][2005],up[2005][2005],down[2005][2005];
char a[2005][2005];

int main()
{
    fastio();
    cin>>n>>m;
    rep(i,1,n) cin>>a[i]+1;
    rep(i,1,n){
        int now = 0;
        rep(j,1,m){
            if(a[i][j]=='#') now = j;
            else lft[i][j] = j-now;
        }
    }
    rep(i,1,n){
        int now = m+1;
        per(j,m,1){
            if(a[i][j]=='#') now = j;
            else rgt[i][j] = now-j;
        }
    }
    rep(j,1,m){
        int now = 0;
        rep(i,1,n){
            if(a[i][j]=='#') now = i;
            else up[i][j] = i-now;
        }
    }
    rep(j,1,m){
        int now = n+1;
        per(i,n,1){
            if(a[i][j]=='#') now = i;
            else down[i][j] = now-i;
        }
    }
    int ans = 0;
    rep(i,1,n) rep(j,1,m) if(a[i][j]=='.') ans = max(ans,lft[i][j]+rgt[i][j]+up[i][j]+down[i][j]-3);
    cout<<ans<<endl;
    return 0;
}
