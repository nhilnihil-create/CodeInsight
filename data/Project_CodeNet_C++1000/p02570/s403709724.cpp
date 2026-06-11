#include<iostream>
using namespace std;

int main()
{
    int d,t,s;
    cin>>d>>t>>s;
    double time=double(d)/s;
    time<=t ? cout<<"Yes" : cout<<"No";
    cout<<endl;

return 0;
}
