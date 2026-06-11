//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll a,b,i;
    cin>>a>>b;
    if(a>=1&&a<=9)
    {
        if(b>=1&&b<=9)
        {
            cout<<a*b<<endl;

        }
    else
        cout<<-1<<endl;
    }
    else
        cout<<-1<<endl;


    return 0;
}



