#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mx 100005
vector<ll>prime;
bool vis[mx];
void seive()
{
    ll x=sqrt(mx);
    for(int i=3;i<=x;i+=2)
    {
        if(vis[i]==false)
        {
            for(int j=i*i;j<mx;j+=2*i)
            {
                vis[j]=true;
            }
        }
    }
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(vis[i]==false)
        {
             prime.pb(i);
        }

    }


}
int main()
{

    seive();
    ll n;
    cin>>n;
    ll x=lower_bound(prime.begin(),prime.end(),n)-prime.begin();
    cout<<prime[x]<<endl;



}

