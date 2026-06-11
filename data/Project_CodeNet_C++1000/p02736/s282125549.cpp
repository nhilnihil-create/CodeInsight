#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define ar array
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld n,m;
lld arr[3000000];
string st;
int main()
{
     ios;
     lld TESTS,q,a,s,b,r,k,c,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
//     ans=0;
     //cin>>TESTS;
   //  memset(dpt,0,sizeof(dpt));memset(dput,0,sizeof(dput));
    // memset(dsu1,0,sizeof(dsu1));
     while(TESTS--)
     {
         bool cont=false;
         cin>>n;
         cin>>st;
         rep(i,0,n-1) if (st[i]=='2')cont=true;
         rep(i,0,n-1){
             if (cont){
                (st[i]=='1'||st[i]=='3')?arr[i]=1:arr[i]=0;
             }
             else (st[i]=='1')?arr[i]=1:arr[i]=0;
            // cout<<arr[i]<<" ";
         }
         lld change=0;
         rep(i,0,n-1) if (arr[i]&&((n-1)&i)==i)change^=1;
         (change)?((cont)?cout<<1:cout<<2):cout<<0;
     }
    return 0;
}
