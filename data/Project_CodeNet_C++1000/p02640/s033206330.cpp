#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(2*a>b||4*a<b)
    {
        cout<<"No"<<endl;
    }
    else if(b%2==1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
