#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;


int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,mn,mx,sum=0;

    cin>>n;

    vector< ll > arr(n-1),ans;

    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }

    ans.push_back(arr[n-2]);

    for(int i=n-2;i>=1;i--)
    {
        if(arr[i-1]<arr[i])
        {
            ans.push_back(arr[i-1]);
        }
        else
        {
            ans.push_back(arr[i]);
        }
    }

    ans.push_back(arr[0]);

    sum=0;
    for(int i=0;i<ans.size();i++)
    {
        sum+=ans[i];
    }

    cout<<sum<<endl;


}
