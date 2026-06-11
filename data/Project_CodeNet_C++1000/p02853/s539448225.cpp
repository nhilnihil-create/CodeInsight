#include <iostream>

using namespace std;
long long a,b,ans;
int main()
{
    cin>>a>>b;
    if(a<4)
    {
        ans+=(4-a)*1e5 ;
    }
    if(b<4)
    {
        ans+=(4-b)*1e5;
    }
    if(a+b==2)
        ans+=4*1e5;
    cout<<ans;
    return 0;
}
