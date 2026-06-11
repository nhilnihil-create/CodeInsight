#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    double  w , h, x, y;
    cin>>w>>h>>x>>y;
    double ans =( w  * h )/2;
    cout.precision(15);
    cout<<ans<<" ";
    if( w/2 == x && h/2 == y )
    {
        cout<<1;
    }
    else cout<<0;
}