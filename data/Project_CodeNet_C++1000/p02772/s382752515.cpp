#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,count1=0,count2=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        {
            count1++;
            if(a[i]%3==0 || a[i]%5==0)
            {
                count2++;
            }
        }
    }
    if(count1==count2)
    {
        cout<<"APPROVED";
    }
    else{cout<<"DENIED";}
}
