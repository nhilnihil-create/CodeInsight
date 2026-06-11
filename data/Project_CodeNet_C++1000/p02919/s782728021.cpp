///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;

 main()

{
    fast
    int n;
    cin>>n;
    int a[n+2];
    f(i,1,n)
    {
        int x;
        cin>>x;
        a[x]=i;
    }
    set<int>s;
    set<int>::iterator it;
    int ses=0;
    for(int i=n;i>=1;i--)
    {
        int pos=a[i];
        it=s.lower_bound(pos);
        int lft_boro,lft_aro_boro,rgt_boro;
        if(it==s.begin())
        {
            s.insert(pos);
            continue;
        }
        it--;
        lft_boro=*it;
        if(it==s.begin())lft_aro_boro=0;
        else
        {
            it--;
            lft_aro_boro=*it;
        }
        it=s.upper_bound(pos);
        if(it==s.end())rgt_boro=n+1;
        else rgt_boro=*it;
        int lft=(lft_boro-lft_aro_boro);
        int rgt=(rgt_boro-pos);
        int way=(lft*rgt);
        ses+=(way*i);
//        cout<<"value        : "<<i<<endl;
//        cout<<"lft boro     : "<<lft_boro<<endl;
//        cout<<"lft_aro_boro : "<<lft_aro_boro<<endl;
//        cout<<"rgt_boro     : "<<rgt_boro<<endl;
//        cout<<"..........................................."<<endl;
        s.insert(pos);
    }
    s.clear();
    for(int i=n;i>=1;i--)
    {
        int pos=a[i];
        it=s.upper_bound(pos);
        int lft_boro,rgt_boro,rgt_aro_boro;
        if(it==s.end())
        {
            s.insert(pos);
            continue;
        }
        rgt_boro=*it;
        it++;
        if(it==s.end())rgt_aro_boro=n+1;
        else rgt_aro_boro=*it;
        it=s.upper_bound(pos);
        if(it==s.begin())lft_boro=0;
        else
        {
            it--;
            lft_boro=*it;
        }
        int lft=pos-lft_boro;
        int rgt=rgt_aro_boro-rgt_boro;
        int way=lft*rgt;
        ses+=(way*i);
//        cout<<"value         : "<<i<<endl;
//        cout<<"lft boro      : "<<lft_boro<<endl;
//        cout<<"rgt_boro      : "<<rgt_boro<<endl;
//         cout<<"rgt_aro_boro : "<<rgt_aro_boro<<endl;
//         cout<<"lft          : "<<lft<<endl;
//         cout<<"rgt          : "<<rgt<<endl;
//         cout<<"way          : "<<way<<endl;
//        cout<<"..........................................."<<endl;
        s.insert(pos);
    }
    cout<<ses<<endl;
    return 0;

}



































