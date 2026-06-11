#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,count=0;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    for(i=0; i<n; i+=2)
    {
        if(a[i]%2==1)
            count++;
    }
    cout<<count;
    return 0;
}
