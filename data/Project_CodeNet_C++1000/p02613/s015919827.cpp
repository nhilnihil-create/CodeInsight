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
        ll n;
        cin>>n;

        ll ac=0,wa=0,tle=0,re=0;
        for( int i=0 ; i<n ; i++ )
        {
            string s;
            cin>>s;

            if(s=="AC")
                ac++;
            else if( s=="WA" )
                wa++;
            else if( s=="TLE" )
                tle++;
            else
                re++;
        }

        cout<<"AC x "<<ac<<endl
            <<"WA x "<<wa<<endl
            <<"TLE x "<<tle<<endl
            <<"RE x "<<re;
    }
    return 0;
}
