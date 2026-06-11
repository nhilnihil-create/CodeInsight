#include<bits/stdc++.h>
#include<cassert>
#include<array>
#define ll long long
#define endl "\n"
#define pb push_back
#define READ(FILE) freopen(FILE,"r",stdin)
#define WRITE(FILE) freopen(FILE,"w",stdout)
#define loop(i,s,e) for(int i=s;i<e;i++)
#define mego fast();
using namespace std;
void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll lcm(ll x, ll y)
{
    return (x*y)/__gcd(x,y);
}
/*const int N=500000;
ll seg[4*N];
ll arr[N+5];
void bulid(int s,int e,int p)
{
    if(s==e)
    {
         seg[p]=arr[s];
         return;
    }
    bulid(s,(s+e)/2,2*p);
    bulid((s+e)/2 +1,e,2*p +1);
    seg[p]=__gcd(seg[2*p],seg[2*p +1]);
    return;
}
void seti(int s,int e,int p,int i,int v)
{
    if(s==e && s==i)
    {
         seg[p]=arr[i]=v;
         return;
    }
    if(i >(s+e)/2)
    seti((s+e)/2 +1,e,2*p +1,i,v);
    else seti(s,(s+e)/2,2*p,i,v);
    seg[p]=__gcd(seg[2*p],seg[2*p +1]);
    return;
}
int flr(int s,int e,int p,int l,int r)
{
    if(l<=s&&e<=r)return seg[p];
    if(s>r || e<l)return 0;
    return __gcd(flr(s,(s+e)/2,2*p,l,r),flr((s+e)/2+1 ,e ,2*p +1 ,l,r));
}
*/
int main()
{
    mego
int n,x;
cin>>n;
vector<int> v;
loop(i,0,n)
{
    cin>>x;
    v.pb(x);
}

ll cur=(1000);
loop(i,0,n-1)
{
    ll s=(cur/v[i]);
if(v[i+1]>v[i])
    cur+=(v[i+1]-v[i])*s;
   }
cout<<cur;
   return 0;
}
