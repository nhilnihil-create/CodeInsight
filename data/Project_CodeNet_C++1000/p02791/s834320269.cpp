#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int cnt,s;
    cnt=1,s=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=s)
        {
            cnt++;
            s=a[i];
        }
    }
    cout<<cnt<<endl;
}
