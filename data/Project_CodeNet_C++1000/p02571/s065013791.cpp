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

    string s,t; cin>>s>>t; ll i,j;
    
    ll p=s.length(); ll q=t.length(); ll x=(p-q)+1;
    
    ll minimum=INF;
    
    for1(i,0,x-1)
    {
         
        ll f=0;
        
        for1(j,i,i+(q-1))
        {
        
            if(s[j]!=t[j-i]) f++;

        
        }

        minimum=min(minimum,f);
    
    }
    
    cout<<minimum<<"\n";
    
}