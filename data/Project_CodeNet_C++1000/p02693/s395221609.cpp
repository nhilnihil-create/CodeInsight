#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define pi 3.141592653589793238

int main()
{
    int t=1;
    //cin>>t;


    while( t-- )
    {
        int k,a,b;
        cin>>k>>a>>b;

        if( a%k==0 )
            cout<<"OK"<<endl;
        else
        {
            if( a+k-(a%k)<=b )
                cout<<"OK"<<endl;
            else
                cout<<"NG"<<endl;
        }

    }
    return 0;
}
