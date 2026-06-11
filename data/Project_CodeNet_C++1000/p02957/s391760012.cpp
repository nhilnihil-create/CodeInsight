#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if((max(a,b)-min(a,b))%2==0)
    cout<<min(a,b)+((max(a,b)-min(a,b))/2)<<endl;
   else
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}



