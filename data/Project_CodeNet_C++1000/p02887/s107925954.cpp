#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>mp;

int main ()
{
    ll n;
    string a,b="";
    cin>>n;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[b.size()-1])
            b+=a[i];
    }
    cout<<b.size()<<endl;
    return 0;

}
