/*
        ALLAH HOAKBAR

        Showkat Reza
        Dept of ICT
        Comilla University

        reminder=20000/30;
        reminder= 666;
*/
#include <bits/stdc++.h>
using namespace std;
#define     LL      long long int
#define     yes     cout<<"YES"<<endl
#define     no     cout<<"NO"<<endl


vector<LL> v,v2,v3;


void read()
{
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    LL x=a*c;
    LL y=b*d;
    LL z=a*d;
    LL t=b*c;
    cout<<max(max(x,y),max(z,t))<<endl;


}


int main()
{
    read();
    //solve();
    return 0;

}
