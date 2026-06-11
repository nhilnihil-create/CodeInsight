#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if(a>=k)
        cout<<(a-k)<<" "<<b<<endl;
    else
    {
        cout<<"0 ";
        k-=a;
        if(b>k)
            cout<<b-k<<endl;
        else
            cout<<"0"<<endl;
    }
}
