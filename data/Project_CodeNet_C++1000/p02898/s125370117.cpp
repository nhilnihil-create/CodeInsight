#include<iostream>
using namespace std;
int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ans+=a>=k;
    }
    cout<<ans;
}