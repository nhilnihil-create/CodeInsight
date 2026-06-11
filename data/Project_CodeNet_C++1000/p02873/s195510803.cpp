#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> left(n+1);
    vector<int> right(n+1);
    int prev=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='<')
        {
            left[i+1]=prev+1;
            prev++;
        }
        else
        {
            left[i+1]=0;
            prev=0;
        }
    }
    prev=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='>')
        {
            right[i]=prev+1;
            prev++;
        }
        else
        {
            right[i]=0;
            prev=0;
        }
    }
    long long ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=max(left[i],right[i]);
    }
    cout<<ans;
    return 0;
}


