
#include<bits/stdc++.h>
#define u64 uint64_t
#define ll long long
#define endl "\n"
#define pi acos(-1)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    fast
    ll n,m,x,y,i,j,k,p,f=0,tc,cnt=0,sum=0,pro=1,mi=1e18,ma=-1e18;
    string str;
    char ch;
    double db;
    deque<ll>dq;
    map<ll,ll>mp;
    set<ll>st;
    vector<ll>vt;
    //code
    ll h1,h2,m1,m2,h;
    cin>>h1>>m1>>h2>>m2>>x;
    ll t1=h1*60+m1;
    ll t2=h2*60+m2;
    if(t1<=t2)
   cout<<t2-t1-x<<endl;
   else
   {
       n=t2;
       n+=(24*60-t1);
       cout<<n-x<<endl;
   }


    //code
    return 0;
}
