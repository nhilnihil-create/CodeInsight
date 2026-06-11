#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a;
    long long ans=0;
    cin>>a;
    long long b=a;
    while(n>1)
    {
        cin>>a;
        if(a>b)
        {
            b=max(a,b);
        }
        if(a<b)
        {
            ans+=b-a;
            b=max(a,b);
        }
        n--;
    }
    cout<<ans<<endl;
    return 0;
}
