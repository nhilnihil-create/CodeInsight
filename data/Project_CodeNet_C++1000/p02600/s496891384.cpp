#include<bits/stdc++.h>
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define ll long long int
using namespace std;
int main()
{
    ll tc, a,b,c,n,x,y,z,cnt=0,sum=0;
    string str;
    cin>>x;
    if(x>=400 && x<600)cout<<8<<endl;
    else if(x>=600 && x<800)cout<<7<<endl;
    else if(x>=800 && x<1000)cout<<6<<endl;
    else if(x>=1000 && x<1200)cout<<5<<endl;
    else if(x>=1200 && x<1400)cout<<4<<endl;
    else if(x>=1400 && x<1600)cout<<3<<endl;
    else if(x>=1600 && x<1800)cout<<2<<endl;
    else if(x>=1800 && x<2000)cout<<1<<endl;
}
