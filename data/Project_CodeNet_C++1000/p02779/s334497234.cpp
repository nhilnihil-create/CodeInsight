#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,i;
    cin>>n;
    long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i+1<n;i++)
    {
        if(a[i]==a[i+1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
