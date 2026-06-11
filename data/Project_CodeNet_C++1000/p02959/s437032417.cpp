#include <bits/stdc++.h>

#define pb              push_back
#define pi              acos(-1.0)
#define loop(i,a,n)     for(int i=a;i<n;i++)
#define rloop(i,n,a)    for(int i=n;i>=a;i--)
#define ll              long long int
#define ff              first
#define ss              second
#define pii             pair<ll,ll>
#define sc1(a)          scanf("%d",&a)
#define sc2(a,b)        scanf("%d %d",&a,&b)
#define sc3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define all(v)          v.begin(),v.end()
#define ms(a,b)         memset(a,b,sizeof a)
#define FastIO          ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define fileout         freopen("output.txt","w",stdout)
#define filein          freopen("input.txt","r",stdin)
#define inf             2e9+5
#define Q               int q;cin>>q;while(q--)
#define check           cout<<"HI"<<endl;

//int x[]= {-1,0,0,1};
//int y[]= {0,-1,1,0};

using namespace std;

int main()
{
    
    int n;
    ll s=0,p;
    sc1(n);
    int a[n+5];
    int b[n+5];
    loop(i,0,n+1)sc1(a[i]);
    loop(i,0,n)sc1(b[i]);

    loop(i,0,n)
    {
        p = min(b[i],a[i]);
        s+=p;
        b[i]-=p;
        a[i]-=p;
        p = min(b[i],a[i+1]);
        s+=p;
        b[i]-=p;
        a[i+1]-=p;
       // cout<<b[i]<<endl;
    }
    //loop(i,0,n)

    cout<<s<<endl;
    
}











