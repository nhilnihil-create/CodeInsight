#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>c(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        c[i]=v[i];
    }
    sort(v.begin(),v.end());
    if(n==1)
    {
        cout<<"0"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if(c[i]==v[n-1])
        {
            cout<<v[n-2]<<endl;
        }
        else cout<<v[n-1]<<endl;
    }
}
