#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define INFL 2000000000000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define togglebit(n,i) ((n)^(1LL<<(i)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007LL)
#define asz 500005
int main()
{
    fastread;
    int T=1;
//    cin>>T;
    for(int qq=1;qq<=T;qq++)
    {
        int n,k;
        cin>>n>>k;
        cout<<(n%k)<<endl;
    }
}
