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
        char c;
        cin>>c;

        if( c>='A' && c<='Z' )
            cout<<"A";
        else
            cout<<"a";
    }
    return 0;
}
