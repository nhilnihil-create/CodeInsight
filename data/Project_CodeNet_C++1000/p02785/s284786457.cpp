#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int h,n;
        cin>>n>>h;
        vector<ll>a(n);
        ll sum=0;
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            // sum+=a[i];
        }
        sort(a.begin(),a.end());
        // int sum=0;
        for(int i=0;i<min(n,n-h);i++)
        sum+=a[i];
        cout<<sum;
    }
	return 0;
}