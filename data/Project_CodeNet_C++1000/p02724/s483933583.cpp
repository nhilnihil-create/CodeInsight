


#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
   
   ll coins;
   cin>>coins;
   ll fiv=coins/500;
   ll ans=0;
    ans+=fiv*1000;
    coins-=fiv*500;
    fiv=coins/5;
    ans+=fiv*5;
    cout<<ans<<endl;

    return 0;
}