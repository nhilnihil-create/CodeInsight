#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    ll l,r;
    ll mn=2019;
    cin>>l>>r;
    for(ll i=l;i<=min(r,l+2019);i++)
    {
        for(ll j=l;j<=min(r,l+2019);j++)
        {
            if(i==j)
                continue;
            mn=min((i*j)%2019, mn);
        }
    }
    cout<<mn<<endl;


}










































