#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
bool vis[100005]={0};
vector<ll>v;
void seive()
{
    for(int i=3;i<=sqrt(mx);i+=2)
    {
        if(vis[i]==0)
        {
            for(int j=i*i;j<mx;j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
    v.push_back(2);
    for(int i=3;i<mx;i+=2)
    {
        if(vis[i]==0)
        {
            v.push_back(i);
        }
    }

}
int main()
{

    seive();
    ll n;
    cin>>n;
    ll x=lower_bound(v.begin(),v.end(),n)-v.begin();
    cout<<v[x]<<endl;


}

