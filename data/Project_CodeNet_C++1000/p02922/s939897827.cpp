#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,total=1,ans=0;
    cin>>a>>b;
    if(b==1)
    {
        cout<<0;
        return 0;
    }
    while(total<b)
    {
        ++ans;
        total+=a-1;
      //  cout<<total<<'\n';
    }
    cout<<ans;
    return 0;
}

