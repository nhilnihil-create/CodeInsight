//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i;
    string s;
    cin>>s;
    for(i=1; s[i]; i++)
    {
    if(s[i-1]==s[i])
        return cout<<"Bad"<<endl,0;
    }
    cout<<"Good"<<endl;
   return 0;
}



