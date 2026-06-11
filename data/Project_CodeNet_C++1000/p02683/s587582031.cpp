#include <bits/stdc++.h>

using namespace std;
#define inf             0x3f3f3f3f
#define INF             2e18
#define eps             1e-9

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define fRead           freopen("input.txt","r",stdin)
#define fWrite          freopen("output.txt","w",stdout)

#define LL              long long
#define ull            unsigned long long
#define PI              acos(-1.0)
#define pb              push_back
#define mk              make_pair
#define pii             pair<int,int>
#define pLL             pair<LL,LL>
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define SQR(a)          ((a)*(a))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define vi              vector <int>
#define vL              vector <LL>
#define LB(a,x)         (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)         (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define prec(n)         fixed << setprecision(n)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)
int main()
{
    LL n,m,x;
    cin>>n>>m>>x;
    vector<LL>v(n,0),s(n,0);
    LL a[n][m];
    for(LL i=0; i<n; i++)
    {
        cin>>v[i];
        for(LL j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }

    LL ans=INF;

    LL f=0;

    for(LL i=0; i<(1<<n); i++)
    {
        LL b[m]= {0};
         LL st=0;
        for(LL j=0; j<n; j++)
        {
            if(i&(1<<j))
            {
                for(LL k=0; k<m; k++)
                {
                    b[k]+=a[j][k];
                }
                st+=v[j];
            }
        }
        LL f=0;
        for(LL j=0;j<m;j++)
        {
          if(x>b[j])f=1;
        }
        if(f==0)
        {
            ans=min(ans,st);
        }

    }
    if(ans==INF)ans=-1;
    cout<<ans;




}
