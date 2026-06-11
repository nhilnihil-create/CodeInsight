#include<bits/stdc++.h>
using namespace std;
#define task "atcoder"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=200005;
string s;
int n,f[N],cnt[3000];

int pw(int n, int k)
{
    if(k==1) return n;
    if(k==0) return 1;
    int t=pw(n,k/2);
    if(k&1) return (t*t%2019)*n%2019;
    else return t*t%2019;
}
void solve()
{
    cin>>s;
    s=' '+s;
    n=s.size()-1;
    ///1234
    for(int i=1;i<=n;++i)
    {
        int c=s[i]-'0';
        f[i]=(f[i-1]+c*pw(10,n-i)%2019)%2019;
    }
    ll ans=0;
    cnt[0]=1;
    for(int i=1;i<=n;++i)
    {
        ans+=cnt[f[i]];
        ++cnt[f[i]];
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}



