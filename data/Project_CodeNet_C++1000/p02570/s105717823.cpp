#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    double d,t,s;
    cin>>d>>t>>s;
    double ans=d/s;
    if(ans<=t)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}