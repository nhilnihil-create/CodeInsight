///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int n;
string s;

bool chk(int x)
{
    map<string,int>fst;
    map<string,int>lst;
    f(i,0,n-1)
    {
        string p=s.substr(i,x);
        if(p.size()<x)break;
        if(fst.count(p)==0)
        {
            fst[p]=i;
        }
    }
     rf(i,n-1,0)
    {
        string p=s.substr(i,x);
        if(p.size()<x)continue;
        if(lst.count(p)==0)
        {
            lst[p]=i;
        }
    }
     for(auto yo:fst)
     {
         int lft=yo.si;
         int rgt=lst[yo.fi];
         if(lft+x<=rgt)
         {
             return true;
         }
     }
     return false;

}
 main()

{
    fast
    cin>>n;
    cin>>s;
    int lo=0,hi=n;
    while(hi-lo>=2)
    {
        int mid=(lo+hi)>>1;
        if(chk(mid))
        {
            lo=mid;
        }
        else hi=mid-1;
    }
    int ses=0;
    f(i,lo,hi)
    {
        if(chk(i))ses=i;
    }
    cout<<ses<<endl;
    return 0;

}











