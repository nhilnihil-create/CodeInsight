#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    vector<int> left(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(str[i-1]=='<')
            left[i]=left[i-1]+1;
        else
            left[i]=0;
    }
    vector<int> right(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='>')
        {
            right[i]=right[i+1]+1;
        }
        else
        {
            right[i]=0;
        }
    }
    long long sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=(1ll*max(left[i],right[i]));
    }
    cout<<sum<<"\n";
    return 0;
}