//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}

int main()
{
    ios;
    ll n;
    cin>>n;
    ll ans1,ans2;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans1=i;
            ans2=n/i;
        }
    }
 
    cout<<ans1+ans2-2<<endl;




}













