#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,k,d,ans;
    cin>>x>>k>>d;
    x=abs(x);
    long long c=x/d;
    ans=x-min(k,c)*d;
    if(k<=c || (k-c)%2==0){
         cout<<abs(ans);
    }
    else
        cout<<abs(ans-d);
}
