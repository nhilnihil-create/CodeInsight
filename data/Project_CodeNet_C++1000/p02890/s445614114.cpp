#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=300010;
int n,f[N],x,sum[N],mid;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        f[x]++;
    }
    f[0]=inf; sort(f,f+n+1); reverse(f,f+n+1);
    fori(1,n+1)
        sum[i]=sum[i-1]+f[i];
    mid=1;
    fori(1,n+1)
    {
        x=sum[n]-sum[i];
        while(f[mid]*(i-mid)-(sum[i]-sum[mid])>x)
            mid++;
        cout<<f[mid]+(x-f[mid]*(i-mid)+sum[i]-sum[mid])/(i-mid+1)<<"\n";
    }
    return 0;
}
