#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
#define infin ll(pow(10,9)+7)
using namespace std;
int main()
{
    ll n,ans1=1,ans2=1,ans3=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ans1=(ans1*10)%infin;
        ans2=(ans2*9)%infin;
        ans3=(ans3*8)%infin;
    }
    ll ans=(ans1-2*ans2+ans3+2*infin)%infin;
    cout<<ans<<endl;
}
