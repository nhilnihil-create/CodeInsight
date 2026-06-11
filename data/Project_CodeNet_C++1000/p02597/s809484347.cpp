#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int w=0,r=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='W')
            w++;
        else
            r++;
    }
    ans=min(w,r);
    int count=0;
    for(int i=0;i<r;i++)
    {
        if(s[i]=='W')
        {
            count++;

        }
    }
    ans=min(ans,count);
    cout<<ans<<endl;

}
