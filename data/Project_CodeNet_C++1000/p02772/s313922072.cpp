#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    lli a[n],i;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0 && a[i]%3!=0 && a[i]%5!=0)
        {
             cout<<"DENIED"<<"\n";
             return 0;
        }
    }
     cout<<"APPROVED"<<"\n";
}
    