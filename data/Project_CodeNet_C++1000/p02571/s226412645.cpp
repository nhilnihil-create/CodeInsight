#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
 
 
main()
{
    string s,t;
    cin>>s>>t;
    int m=s.size(),n=t.size();
    int ans=1e9;
    for(int i=0;i<m-n+1;i++)
    {
        int count=0;
        string a = s.substr(i,n);
        for(int j=0;j<n;j++)
        {
            if(a[j]!=t[j])
            {
                count++;
            }
        }
        ans = min(ans,count);
    }
    cout<<ans<<endl;
}