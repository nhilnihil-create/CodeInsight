#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]!=i)
        {
            count++;
        }
    }
    if(count<=2)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
}
