#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{

    string s,t;
    cin>>s>>t;
    ll c=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]!=t[i])
            c++;
    }
    cout<<c<<endl;




}
