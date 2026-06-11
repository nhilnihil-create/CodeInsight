//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==4||a==6||a==9||a==11)
    {
        if(b==30)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }

    else if(a==2)
    {
        if(b==28)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    else
    {
        if(b==31)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }


    return 0;
}



