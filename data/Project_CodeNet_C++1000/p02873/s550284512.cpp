///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


 main()

{
    fast
    string s;
    cin>>s;
    int sz=s.size();
    int ses=0;
    int a[sz+2];
    s="#"+s;
    a[0]=0;
    int last=0;
    for(int i=1;i<=sz;i++)
    {
        char ch=s[i];
        int lft=i,rgt=i;
        for(int j=i+1;j<=sz;j++)
        {
            if(s[j]==ch)rgt++;
            else break;
        }
       // cout<<ch<<" "<<lft<<" "<<rgt<<endl;
        if(ch=='<')
        {
             for(int j=lft,k=1;j<=rgt;j++,k++)
             {
                 a[j]=k;
             }
        }
        else
        {
            for(int j=rgt,k=0;j>=lft;j--,k++)
            {
                a[j]=k;
            }
           if(a[lft]>=a[lft-1])
           {
               a[lft-1]=a[lft]+1;
           }
        }
         i=rgt;
    }

    f(i,0,sz)
    {
        ses+=a[i];
        //cout<<a[i]<<" ";
    }
    //cout<<endl;
    cout<<ses<<endl;

    return 0;

}



































