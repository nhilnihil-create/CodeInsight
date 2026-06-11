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

        int a;

        ll sum=0;
        map <ll , ll> m;

        for( int i=0 ; i<n ; i++ )
        {
            cin>>a;
            m[a]++;
            sum+=a;
        }
        //cout<<sum<<endl;

        int q;
        cin>>q;

        while( q-- )
        {
            int b,c;
            cin>>b>>c;

            sum=sum-b*m[b]-c*m[c];
            m[c]+=m[b];

            //cout<<"sum = "<<sum<<" - "<<m[b]*b<<" + "<<m[c]*c<<endl;
            sum = sum + (m[c]*c) ;
            m[b]=0;

            cout<<sum<<endl;
        }
    }
    return 0;
}
