#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int flag=0;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]>=a[i-1])
            continue;
        else
        {
            if(abs(a[i]-a[i-1])==1)
                a[i-1]-=1;
            else
            {flag=1;break;}
        }
    }
    if(flag==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}