#include <iostream>
#include <map>
#define ll long long

using namespace std;

map <ll,int> mp;

int main()
{
    ll n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       ll x;
       cin>>x;
       ans+=mp[i-x];
       mp[i+x]++;
    }
    cout<<ans<<endl;
    return 0;
}
