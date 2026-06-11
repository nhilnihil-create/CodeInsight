#include<bits/stdc++.h>
using namespace std;

#define      pai              acos(-1)
#define      ff               first
#define      ss               second
#define      ll               long long
#define      pb               push_back
#define      mp               make_pair
#define      pll              pair<ll,ll>
#define      sz(a)            (ll)a.size()
#define      endl             "\n"
#define      gcd(a, b)        __gcd(a, b)
#define      lcm(a, b)        ((a)*((b)/gcd(a,b))
#define      all(vec)         vec.begin(),vec.end()
#define      ms(a, b)         memset(a,b,sizeof(a))
#define      TEST_CASE(t)     for(int zz=1;zz<=t;zz++)
#define      PRINT_CASE       printf("Case %d: ",zz)
#define      fii              freopen("input.txt","r",stdin);
#define      foo              freopen("output.txt","w",stdout);
#define      FAST             ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const ll M   = 1e9+7;
const ll mxn = 3e5+10;
vector<pll>row(mxn),col(mxn);
set<pll>st;
int  main()
{
    ll i,j,k,a,b,c,d,n,m,t,h,u,v,w,x,y,z;
    cin>>x>>y>>n;

    for(i=1;i<=n;i++)
    {
        cin>>u>>v;
        st.insert({u,v});
        row[u].ff+=1;
        row[u].ss=u;
        col[v].ff+=1;
        col[v].ss=v;
    }
    ll mxr=0,mxc=0;
    for(auto a:row)
    {
        mxr=max(mxr,a.ff);
    }
    for(auto a:col)
    {
        mxc=max(mxc,a.ff);
    }
    set<ll>stw,sth;
    for(auto a:row)
    {
        if(a.ff==mxr)
        {
            stw.insert(a.ss);
        }
    }
    for(auto a:col)
    {
        if(a.ff==mxc)
        {
            sth.insert(a.ss);
        }
    }
    for(auto a:stw)
    {
        for(auto b:sth)
        {
            if(st.find({a,b})==st.end())
            {
                cout<<mxr+mxc<<endl;
                return 0;
            }
        }
    }
    cout<<mxr+mxc-1<<endl;
    return 0;
}
