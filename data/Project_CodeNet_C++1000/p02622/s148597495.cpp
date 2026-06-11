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
        string s,t;
        cin>>s>>t;

        int ctr=0;
        for( int i=0 ; i<s.size() ; i++ )
            if( s[i]!=t[i] )
            ctr++;

        cout<<ctr;
    }
    return 0;
}
