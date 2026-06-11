#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    string s;cin>>s;
    if(s=="Sunny")
    cout<<"Cloudy"<<endl;
    else if(s=="Cloudy")
    cout<<"Rainy"<<endl;
    else
    cout<<"Sunny"<<endl;
}
int32_t main()
{
         rapido;
         int t;
         //cin>>t;
         t=1;
         while(t--)
         solve();
}