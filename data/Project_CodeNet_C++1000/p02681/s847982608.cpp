#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf (ll)(1e18)
#define mod 1000000007

int main()
{
    int t=1;
    //cin>>t;

    while( t-- )
    {
        string s1,s2;
        cin>>s1>>s2;
        bool flag=1;
        for( int i=0 ; i<s1.size() ; i++ )
            if( s1[i]!=s2[i] )
            {
                flag=0;
                break;
            }

        if( flag )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}










