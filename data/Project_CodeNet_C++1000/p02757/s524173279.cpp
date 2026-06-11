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

map<int,int>cnt;

 main()

{
    fast
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int sum=0;
    int ses=0;
    int ten=1;
    if(p==2 || p==5)
    {

         f(i,0,n-1)
         {
             if((s[i]-'0')%p==0)
             {
                 ses+=(n-i);
             }
         }
        cout<<ses<<endl;
        return 0;
    }
    cnt[0]++;
    f(i,0,n-1)
    {
        int val=(s[i]-'0')*ten;
        val=val%p;
        sum=(sum+val)%p;
        if(sum<0)sum+=p;
        sum=sum%p;
        cnt[sum]++;
        ten=(ten*10)%p;
    }
   for(auto x:cnt)
   {
       int yo=x.si;
       int val=(yo*(yo-1))/2;
       ses+=val;
   }
    cout<<ses<<endl;
    return 0;

}












