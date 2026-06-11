#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define togglebit(n,i) ((n)^(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 500005
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define pf push_front
int main()
{
    fastread;
    ll i,j,k,n,m,y,t;
    string s;
    cin>>s;
    if(s[2]==s[3] && s[4]==s[5]) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
