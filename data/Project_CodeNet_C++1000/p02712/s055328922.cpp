#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() 
{
    int n;
    cin>>n;
    ll sum=0;

    for(int i=1;i<=n;i++)
    {
        if(i%5==0 || i%3==0)
        {
            sum=sum+0;
        }
        else
        {
            sum=sum+i;
        }
    }
    cout<<sum<<endl;
    
}
