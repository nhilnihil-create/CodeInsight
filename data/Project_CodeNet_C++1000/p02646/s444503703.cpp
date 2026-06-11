#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,av;
    ll b,bv;
    ll t;
    cin>>a>>av;
    cin>>b>>bv>>t;
    if(av*t-bv*t>=abs(b-a))
         cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
