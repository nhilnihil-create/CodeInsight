#include<bits/stdc++.h>
//#include<pair>
using namespace std;

typedef long long ll;
typedef int ii;
//typedef vector<ll> vi;

#define INF 1000000007

#define pi 3.141592654

#define T while(t--)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define for3(i,a,b) for(i=a;i<=b;i=i+2)
#define for1(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mp make_pair

#include<sstream>

#define si set<ll>
#define se multiset<ll>

typedef long double ld;

typedef vector<ll> vi;

#define bb(arr,nn,xx) upper_bound(arr,arr+nn,xx)-arr
#define aa(arra,nna,xxa) lower_bound(arra,arra+nna,xxa)-arra

#define all(v) sort(v.begin(),v.end())
 
#define all1(v) sort(v.rbegin(),v.rend())

ii main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,i; cin>>n; ll x,y; vector<ll> v,v1;
    
    for1(i,1,n)
    {
    
        cin>>x>>y;
        
        ll p=x+y;
        
        ll p1=y-x;

        v.pb(p);
        
        v1.pb(p1);
        
    }
      
    all(v);
    
    all(v1);
    
    ll q=abs(v[0]-v[n-1]);
    
    ll q1=abs(v1[0]-v1[n-1]);
    
    cout<<max(q,q1)<<"\n";
    
}