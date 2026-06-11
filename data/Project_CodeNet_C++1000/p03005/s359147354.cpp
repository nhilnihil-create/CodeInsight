#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j;
    cin>>n>>k;
    if(k==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==k)
    {
        cout<<0<<endl;
        return 0;
    }
    i=n-k;
    cout<<i<<endl;




    return 0;
}
