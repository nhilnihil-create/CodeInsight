#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,count=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]!=i+1)
            count++;
    }
    if(count<=2)
        cout<<"YES";
    else
        cout<<"NO";

}
