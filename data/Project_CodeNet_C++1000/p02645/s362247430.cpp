#include<bits/stdc++.h>
#define ll long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
int main()
{
    FAST();
    ll t,i,j,k,n,l,x,y;
    vector<ll>v;
    map<ll,ll>m;
    string s;
    cin>>s;
    for(i=0;i<3;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
