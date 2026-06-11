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

vector<int>vec[M+2];

 main()

{
    fast
    int n,m,a,b;
    cin>>n>>m;
    f(i,1,n)
    {
        cin>>a>>b;
        int last=m-a;
        if(last<0)continue;
        vec[last].pb(b);
    }
    set<int>s;
    map<int,int>cnt;
    int ses=0;
    rf(i,M-1,0)
    {
         for(auto x:vec[i])
         {
             s.insert(-x);
             cnt[x]++;
         }
         if(s.size()){
         int mx=*s.begin();
         mx=-mx;
         ses+=mx;
         cnt[mx]--;
         if(cnt[mx]==0)s.erase(-mx);}
    }
    cout<<ses<<endl;
















    return 0;

}











