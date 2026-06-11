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
    int n,m;
    cin>>n>>m;
    int s[m],c[m];
    for(int i=0;i<m;i++)cin>>s[i]>>c[i];
    int x,y;
    if(n==1){
        x=0;
        y=9;
    }
    else if(n==2)
    {
        x=10;
        y=99;
    }
    else
    {
        x=100;
        y=999;
    }
    for(int i=0;i<=1000;i++)
    {
        int p=i;
        vector<int>v;
        v.clear();
        while(p)
        {
            v.pb(p%10);
            p=p/10;
        }
        reverse(all(v));
        if(v.size()==0)v.pb(0);
        if(v.size()!=n)continue;
        int f=0;
        for(int j=0;j<m;j++)
        {
            if(v[s[j]-1]!=c[j])f=1;
        }
        if(f==0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;

}
