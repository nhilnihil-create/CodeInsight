#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    vector<int> ans(n+1,-1);
    bool startZero=false;
    int prev=0;
    if(str[0]=='<')
    {
        ans[0]=0;
        startZero=true;
    }
    for(int i=0;i<n-1;i++)
    {
        // between i-1 and i
        if(str[i]=='>'&&str[i+1]=='<')
        {
            ans[i+1]=0;
            startZero=true;
            prev=0;
            continue;
        }
        if(startZero&&str[i]=='<'&&str[i+1]=='<')
        {
            ++prev;
            ans[i+1]=prev;
        }
        else
        {
            startZero=false;
        }
    }
    startZero=false;
    prev=0;
    if(str[n-1]=='>')
    {
        ans[n]=0;
        startZero=true;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(str[i+1]=='<'&&str[i]=='>')
        {
            ans[i+1]=0;
            startZero=true;
            prev=0;
            continue;
        }
        if(startZero&&str[i]=='>'&&str[i+1]=='>')
        {
            ++prev;
            ans[i+1]=prev;
        }
        else
        {
            startZero=false;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(str[i]=='<'&&str[i+1]=='>')
        {
            ans[i+1]=1+max(ans[i],ans[i+2]);
        }
    }
    if(str[0]=='>')
    {
        ans[0]=1+ans[1];
    }
    if(str[n-1]=='<')
    {
        ans[n]=1+ans[n-1];
    }
    long long sum=0;
    for(auto const&e:ans)
    {
        sum+=e;
    }
    cout<<sum<<"\n";
    return 0;
}
