#include<bits/stdc++.h>
#define ALL(x) (x).begin(),(x).end()
#define ll long long
#define ull unsigned long long
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
const ll M = 1e9+7;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

char s[maxn];
ll f[maxn][2];

int main()
{
    fastio();
    cin>>s+1;
    int n = strlen(s+1);
    f[0][1] = 1;
    rep(i,1,n){
        f[i][0] = f[i-1][0]*3%M;
        f[i][1] = f[i-1][1];
        if(s[i]=='1'){
            f[i][1] = f[i-1][1]*2%M;
            f[i][0] = (f[i][0] + f[i-1][1]) %M;
        }
    }
    cout<<(f[n][0] + f[n][1])%M<<endl;
    return 0;
}
