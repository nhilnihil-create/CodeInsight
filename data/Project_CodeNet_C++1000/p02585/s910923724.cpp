#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl "\n"
#define pi 3.14159265358979323846264338327950288
#define MOD 1000000007
#define INF -100000000000000
#define ordered_set tree<pair< ll int ,ll  int>, null_type,less<pair<ll int, ll int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lld long double
using namespace __gnu_pbds;
int main()
{
    fast;
    ll int n,k;
    cin>>n>>k;
    ll int p[n+1];
    ll int i,ans=INT_MIN;
    for(i=1;i<=n;i++)
        cin>>p[i];
    ll int c[n+1];
    for(i=1;i<=n;i++)
        cin>>c[i];
    for(i=1;i<=n;i++)
    {
       ll int  ind=i;
        ll int q=0,w,start;
        ll int mp[5005]={0},mp1[5005]={0};
        vector<ll int> v;
        while(1)
        {
            //temp.PB(ind);
            mp1[ind]=q++;
           mp[ind]=-1;
           w=p[ind];
           if(mp[w]!=-1)
           {
                ind=w;
                v.PB(c[w]);
           }
           else
           {
                v.PB(c[w]);
                start=mp1[w];
                break;     
           }

        }ll int j,val=0;
        ll int fin;ll int tans=INT_MIN;
        if(k<=v.size())
        {//cout<<"ddj";
    //cout<<v.size()<<endl;
            for(j=0;j<k;j++)
            {
                val+=v[j];//cout<<v[j]<<endl;
                tans=max(val,tans);
            }
            fin=tans;

        }
        else
        {ll int r,t1=0;
           // cout<<start<<endl;
            ll int val=0,t1ans=INT_MIN,t2ans=INT_MIN;
            for(j=0;j<start;j++)
            {
                val+=v[j];
                tans=max(val,tans);
            }
            q=k-(start);
            r=q/(v.size()-start);
            for(j=start;j<v.size();j++)
            {
                t1+=v[j];
                t1ans=max(t1ans,t1);
            }
            w=q%(v.size()-start);
            ll int t2=0;
            for(j=0;j<w;j++)
            {
                t2+=v[start++];
                t2ans=max(t2,t2ans);
            }
            ll int val1=0,val2=0,val3=0;
            if(tans==INT_MIN)
                tans=0;
            if(t1ans==INT_MIN)
                t1ans=0;
            if(t2ans==INT_MIN)
                t2ans=0;
            //cout<<t1<<endl;
            //cout<<tans<<" "<<t1ans<<" "<<t2ans<<endl;
            val1=tans+t1ans;
            val2=tans+t1ans+(r-1)*t1;
            val3=tans+r*t1+t2ans;

           //cout<<val1<<" "<<val2<<" "<<val3<<endl;
            fin=max(val1,max(val2,val3));
          //  cout<<val<<" "<<i<<endl;

        }
        ans=max(fin,ans);
    }
    cout<<ans<<endl;
}

