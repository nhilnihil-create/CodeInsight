#include<bits/stdc++.h>
using namespace std;



int main()
{
    long long n;
    cin>>n;
    if(n%2!=0) { cout<<"0"<<endl; return 0; }
    n=n/2;
    long long ans=0;
    long long id=5;
    while(id<=n)
    {
        ans+=(n/id);
        id*=5;
    }
    cout<<ans<<endl;
}
