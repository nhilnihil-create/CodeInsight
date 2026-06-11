#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int t=1;
    //cin>>t;

    while( t-- )
    {
        ll a;
        string b;

        cin>>a>>b;

        ll c= (b[0]-'0')*100 + (b[2]-'0')*10 + (b[3]-'0');
        c=a*c;
        c=c/100;
        cout<<c;
    }
    return 0;
}
