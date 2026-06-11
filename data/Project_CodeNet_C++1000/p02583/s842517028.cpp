#include<bits/stdc++.h>
using namespace std;

#define                      ff                                          first
#define                      ss                                          second
#define                      pai                                         acos(-1)
#define                      ll                                          long long
#define                      pb                                          push_back
#define                      mp                                          make_pair
#define                      pll                                         pair<ll,ll>
#define                      sz(a)                                       (ll)a.size()




const ll mod  = 1e9 +07;
const ll mxn  = 1e6 +10;

bool valid(ll a, ll b, ll c)
{
    if((a+b)>c && (b+c)>a && (a+c)>b && a<b && a<c && b<c)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int  main(int argc, char const *argv[])
{
    ll i,j,k,a,b,c,d,n,m,t,h,u,v,x,y,z;
    cin>>n;
    vector<ll>vec(n);
    for(auto &a:vec)
    {
        cin>>a;
    }
    sort(vec.begin(),vec.end());
    ll cnt=0;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(valid(vec[i],vec[j],vec[k]))
                {
                    //cout<<"( "<<vec[i]<<" , "<<vec[j]<<" , "<<vec[k]<<" ) "<<endl;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

