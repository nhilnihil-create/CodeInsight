
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,cnt=0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=k)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;



}
