#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    bool turn=true;
    while(1)
    {
        if(turn)
        {
            c-=b;
            if(c<=0)
            {
                cout<<"Yes";
                return 0;
            }
        }
        else 
        {
            a-=d;
            if(a<=0)
            {
                cout<<"No";
                return 0;
            }
        }
        turn=!turn;
    }
}