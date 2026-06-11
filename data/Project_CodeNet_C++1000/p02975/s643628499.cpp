#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,sum=0,a;
    cin>>n;
    while(n--)
    {
        cin>>a;
            sum=sum^a;
    }
    if(sum==0)
        cout<<"Yes";
    else
        cout<<"No";

}
