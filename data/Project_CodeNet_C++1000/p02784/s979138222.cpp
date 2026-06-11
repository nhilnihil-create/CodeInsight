#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int h,n;
        cin>>h>>n;
        vector<int>a(n);
        int sum=0;
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum>=h) cout<<"Yes"; else cout<<"No";
    }
	return 0;
}