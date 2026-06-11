#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{

    ll a,v,b,w,t,x,y;

    cin>>a>>v>>b>>w>>t;


    if(abs(a-b)<=(v-w)*t)
    {
            cout<<"YES\n";
    }

    else
        {

                cout<<"NO\n";
        }


    return 0;

}
