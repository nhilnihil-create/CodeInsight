#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    for(int i=0;i<k;i++)
    {
        if(a>=b)
        {
            b*=2;
        }
        else if(b>=c)
        {
            c*=2;
        }
    }
    if(a<b && b<c)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
